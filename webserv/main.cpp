#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>

#include <string>
#include <map>

#define PORT		8080	// configuration file
#define EPOLL_SIZE	1
#define MAX_EVENTS	10
#define TIMEOUT		500
#define BUFFER_SIZE	4096

class Request {
public:
	std::string	msg;
};

int main(int argc, char **argv)
{
	int					server_socket;
	struct sockaddr_in	addr;

	server_socket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (server_socket < 0)
	{
		std::cerr << strerror(errno) << std::endl;
		return (EXIT_FAILURE);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if (bind(server_socket, reinterpret_cast<struct sockaddr *>(&addr), sizeof(struct sockaddr_in)) < 0)
	{
		std::cerr << strerror(errno) << std::endl;
		return (EXIT_FAILURE);
	}
	if (listen(server_socket, SOMAXCONN) < 0)
	{
		std::cerr << strerror(errno) << std::endl;
		return (EXIT_FAILURE);
	}
	
	int					epoll_fd;
	int					nfds;
	int					connected_socket;
	struct epoll_event	event, events[MAX_EVENTS];

	epoll_fd = epoll_create(EPOLL_SIZE);
	if (epoll_fd < 0)
	{
		std::cerr << strerror(errno) << std::endl;
		return (EXIT_FAILURE);
	}

	event.events = EPOLLIN;	//	TODO: is EPOLLET for server_socket necessary? epoll_wait is blocked anyway.
	event.data.fd = server_socket;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_socket, &event) < 0) // for server-client connection events.
	{
		std::cerr << strerror(errno) << std::endl;	
		exit(EXIT_FAILURE);
	}

	// struct sockaddr_in	client_addr;
	// socklen_t			client_addr_len;

	std::map<int, Request>	req;

	while (1)
	{
		// nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, TIMEOUT);
		nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
		if (nfds < 0)
		{
			std::cerr << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < nfds; i++)
		{
			if (events[i].data.fd == server_socket)
			{
				// connected_socket = accept(server_socket, reinterpret_cast<struct sockaddr *>(&client_addr), &client_addr_len);
				connected_socket = accept(server_socket, 0, 0);
				if (connected_socket < 0)
				{
					std::cerr << strerror(errno) << std::endl;
					return (EXIT_FAILURE);
				}
				fcntl(connected_socket, F_SETFL, O_NONBLOCK);
				event.events = EPOLLIN | EPOLLOUT;
				event.data.fd = connected_socket;
				if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, connected_socket, &event) < 0)
				{
					std::cerr << strerror(errno) << std::endl;
					return (EXIT_FAILURE);
				}
				req[connected_socket] = Request();
			}
			else if (events[i].events & EPOLLIN)
			{
				connected_socket = events[i].data.fd;
				char	buffer[BUFFER_SIZE];
				int		n_bytes = recv(connected_socket, buffer, BUFFER_SIZE, 0);
				if (n_bytes < 0)
				{
					return (EXIT_FAILURE);
				}
				else if (n_bytes == 0)
				{
					close(connected_socket);
					// return (EXIT_SUCCESS);
				}
				else
				{
					req[connected_socket].msg.append(buffer);
					if (req[connected_socket].msg.find("\r\n\r\n") != std::string::npos)
					{
						std::cout << req[connected_socket].msg << std::endl;
					}
				}
			}
			else if (events[i].events & EPOLLOUT)
			{
				connected_socket = events[i].data.fd;
				// how to know which response message to send to which client?
			}
		}
	}
}
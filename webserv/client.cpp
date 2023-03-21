#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <cstring>
#include <iostream>
#define PORT            8080
#define MESSAGE         "h"
#define SERVERHOST      "127.0.0.1"

void
init_sockaddr (struct sockaddr_in *name,
               const char *hostname,
               uint16_t port)
{
  struct hostent *hostinfo;

  name->sin_family = AF_INET;
  name->sin_port = htons (port);
  hostinfo = gethostbyname (hostname);
  if (hostinfo == NULL)
    {
      fprintf (stderr, "Unknown host %s.\n", hostname);
      exit (EXIT_FAILURE);
    }
  name->sin_addr = *(struct in_addr *) hostinfo->h_addr;
}

void
write_to_server (int filedes)
{
  int nbytes;
  int count = 0;
  while (1) {
  nbytes = send (filedes, MESSAGE, strlen (MESSAGE), 0);
  std::cout << ++count << std::endl;
  if (nbytes < 0)
    {
      perror ("write");
      exit (EXIT_FAILURE);
    }

  }
}


int
main (void)
{
  extern void init_sockaddr (struct sockaddr_in *name,
                             const char *hostname,
                             uint16_t port);
  int sock;
  struct sockaddr_in servername;

  /* Create the socket. */
  sock = socket (PF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    {
      perror ("socket (client)");
      exit (EXIT_FAILURE);
    }


  /* Connect to the server. */
  init_sockaddr (&servername, SERVERHOST, PORT);
  if (0 > connect (sock,
                   (struct sockaddr *) &servername,
                   sizeof (servername)))
    {
      perror ("connect (client)");
      exit (EXIT_FAILURE);
    }

  // int buff;
  // socklen_t optlen;
  // getsockopt(sock, SOL_SOCKET, SO_SNDBUF, &buff, &optlen);
  // std::cout << buff << std::endl;
  // getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &buff, &optlen);
  // std::cout << buff << std::endl;
  // while (1) {};


  /* Send data to the server. */
  write_to_server (sock);
  close (sock);
  exit (EXIT_SUCCESS);
}
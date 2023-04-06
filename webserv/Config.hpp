#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <map>
# include <string>
# include <utility>
# include "Server.hpp"

class Config
{
public:
	typedef std::string							Host, Port, ServerName;
	typedef std::pair<Host, Port>				SocketAddr;
	typedef std::map<ServerName, Server>		ServerSubList;
	typedef std::map<SocketAddr, ServerSubList>	ServerList;

private:
	ServerList  serverList;
	
};
#endif
#include <map>
#include <set>
#include <utility>
#include <string>

class HttpConf
{
public:
	typedef std::string				Host, Port, Directive, Argument, Uri, ServerName;
	typedef std::pair<Host, Port>	SocketAddr;

private:
	class LocationConf
	{
	private:
		std::map< Directive, std::set<Argument> >	directives;
	public:

	};

	class ServerConf
	{
	private:
		std::map< Uri, LocationConf >				locationBlocks;
		std::map< Directive, std::set<Argument> >	directives;
	public:
		// addLocationConf() - add LocationConf(directives) to locationBlocks;
		// 
	};

	class SocketAddrServers
	{
	private:
		std::map<ServerName, ServerConf>	serverBlocks;
		static ServerConf					&defaultServer;
	public:
		// addServerConf() - add ServerConf(directives) to serverBlocks;
		// findServerConf(ServerName)
		// setDefaultServer(ServerConf &)
		// getDefaultServer()
	};

	const char									*filePath;
	std::map< SocketAddr, SocketAddrServers >	socketAddrServers;
	std::map< Directive, std::set<Argument> >	directives;

public:
	HttpConf(const char *filePath) {};
	// parse()
	// generateServer
};

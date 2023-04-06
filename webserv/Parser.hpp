#ifndef PARSER_HPP
# define PARSER_HPP

# include "Config.hpp"
# include "Lexer.hpp"
# include "Server.hpp"
# include "Location.hpp"

class Parser
{
public:
	typedef Lexer::Tokens	Tokens;

private:
	Server		parseServerBlock();
	Location	parseLocationBlock();
	
public:
	Config		parse(const Tokens &tokens);
};
#endif

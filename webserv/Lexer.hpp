#ifndef LEXER_H
# define LEXER_H

# include <set>
# include <vector>
# include <string>
# include <fstream>

# define FILEPATH_EXCEPT_MSG	"Invalid File Path!"

class Lexer
{
public:
	typedef std::string			Token, Delimiter, Word;
	typedef std::vector<Token>	Tokens;
	typedef std::ifstream		ConfigFile;

private:
	ConfigFile	configFile;

	Delimiter	WHITESPACES = " \n\t\r\f\v";
	Delimiter	BRACKET_SEMICOLON = "{};";

private:
	void    addToken(Tokens &tokens, Token token, Token delimiter);
	void	processToken(Tokens &tokens);
	bool	isNotDelimiter(char c);
	bool	isWhiteSpaces(char c);
	bool	isBracketOrSemicolon(Delimiter delimiter);

public:
	Lexer(const char *filePath);
	Tokens	tokenize();
};

#endif
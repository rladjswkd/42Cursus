#include "Lexer.hpp"

Lexer::Lexer(const char *filePath) : FILEPATH(filePath)
{
	this->configFile.open(FILEPATH.c_str());
}

bool Lexer::isNotDelimiter(char c)
{
    return (WHITESPACES.find(c) == std::string::npos && BRACKET_SEMICOLON.find(c) == std::string::npos);
}

bool Lexer::isWhiteSpaces(char c)
{
    return (WHITESPACES.find(c) != std::string::npos);
}

bool Lexer::isBracketOrSemicolon(Delimiter delimiter)
{
	return (BRACKET_SEMICOLON.find(delimiter) != std::string::npos);
}

void Lexer::addToken(Tokens &tokens, Token token, Token delimiter)
{
	if (token.size())
		tokens.push_back(token);
	if (isBracketOrSemicolon(delimiter))
		tokens.push_back(delimiter);
}

void Lexer::processToken(Tokens &tokens)
{
	Word			word;
	std::filebuf	*fileBuf = configFile.rdbuf();
	char			currentChar = fileBuf->sgetc();

	while (isWhiteSpaces(currentChar))
		currentChar = fileBuf->snextc();
	while (currentChar != EOF && isNotDelimiter(currentChar))
	{
		word.push_back(currentChar);
		currentChar = fileBuf->snextc();
	}
	addToken(tokens, word, Token(1, currentChar));
	if (currentChar == EOF)
		configFile.setstate(std::ios_base::eofbit);
	fileBuf->sbumpc();
}

Lexer::Tokens Lexer::tokenize()
{
	Tokens	tokens;

	if (!configFile.good())
		throw (std::invalid_argument("Invalid file path!"));
	while (!configFile.eof())
		processToken(tokens);
	configFile.close();
	return (tokens);
}

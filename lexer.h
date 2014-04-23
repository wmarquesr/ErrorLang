#include "token.h"
#include <istream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <exception>

class SyntaxException: public std::exception
{
public:
	const char* what() const throw()
	{
		return "Invalid expression";
	}
};

class Lexer
{
public:
	Lexer(std::istream &in) : in(in), line(1), lexpos(0) {}

	boost::shared_ptr<Token> nextToken();

private:
	std::istream &in;
	std::string buffer;
	int line;
	int lexpos;
};
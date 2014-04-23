#include "token.h"

class LParenToken: public Token
{
public:
	LParenToken() : Token(TOKEN_LPAREN) {}

	operator std::string() const
	{
		return "(LPAREN)";
	}
};

class RParenToken: public Token
{
public:
	RParenToken() : Token(TOKEN_RPAREN) {}

	operator std::string() const
	{
		return "(RPAREN)";
	}
};

class LBraceToken: public Token
{
public:
	LBraceToken() : Token(TOKEN_LBRACE) {}

	operator std::string() const
	{
		return "(LBRACE)";
	}
};

class RBraceToken: public Token
{
public:
	RBraceToken() : Token(TOKEN_RBRACE) {}

	operator std::string() const
	{
		return "(LBRACE)";
	}
};

class LBracketToken: public Token
{
public:
	LBracketToken() : Token(TOKEN_LBRACKET) {}

	operator std::string() const
	{
		return "(LBRACKET)";
	}
};

class RBracketToken: public Token
{
public:
	RBracketToken() : Token(TOKEN_RBRACKET) {}

	operator std::string() const
	{
		return "(RBRACKET)";
	}
};

class CommaToken: public Token
{
public:
	CommaToken() : Token(TOKEN_COMMA) {}

	operator std::string() const
	{
		return "(COMMA)";
	}
};

class SemiColonToken: public Token
{
public:
	SemiColonToken() : Token(TOKEN_SEMICOLON) {}

	operator std::string() const
	{
		return "(SEMICOLON)";
	}
};
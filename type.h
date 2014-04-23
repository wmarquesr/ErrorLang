#include "token.h"

class IdToken: public Token
{
public:
	IdToken(std::string name) : Token(TOKEN_ID), name(name) {}

	operator std::string() const
	{
		return "(ID," + name + ")";
	}

	std::string value() const
	{
		return name;
	}

private:
	std::string name;
};

class IntToken: public Token
{
public:
	IntToken() : Token(TOKEN_INT) {}

	operator std::string() const
	{
		return "(INT)";
	}
};

class FloatToken: public Token
{
public:
	FloatToken() : Token(TOKEN_FLOAT) {}

	operator std::string() const
	{
		return "(FLOAT)";
	}
};

class BoolToken: public Token
{
public:
	BoolToken() : Token(TOKEN_BOOL) {}

	operator std::string() const
	{
		return "(BOOL)";
	}
};

class StringToken: public Token
{
public:
	StringToken() : Token(TOKEN_STRING) {}

	operator std::string() const
	{
		return "(STRING)";
	}
};

class ListToken: public Token
{
public:
	ListToken() : Token(TOKEN_LIST) {}

	operator std::string() const
	{
		return "(LIST)";
	}
};

class VoidToken: public Token
{
public:
	VoidToken() : Token(TOKEN_VOID) {}

	operator std::string() const
	{
		return "(VOID)";
	}
};

class IfToken: public Token
{
public:
	IfToken() : Token(TOKEN_IF) {}

	operator std::string() const
	{
		return "(IF)";
	}
};

class ElseToken: public Token
{
public:
	ElseToken() : Token(TOKEN_ELSE) {}

	operator std::string() const
	{
		return "(ELSE)";
	}
};

class ReturnToken: public Token
{
public:
	ReturnToken() : Token(TOKEN_RETURN) {}

	operator std::string() const
	{
		return "(RETURN)";
	}
};

class WhileToken: public Token
{
public:
	WhileToken() : Token(TOKEN_WHILE) {}

	operator std::string() const
	{
		return "(WHILE)";
	}
};

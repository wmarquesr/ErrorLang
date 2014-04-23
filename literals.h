#include "token.h"
#include <boost/lexical_cast.hpp>

class StringLiteralToken: public Token
{
public:
	StringLiteralToken(std::string value) : Token(TOKEN_STR_LIT), value_(value) {}

	operator std::string() const
	{
		return "(STR_LIT, " + value_ + ")";
	}

	std::string value() const
	{
		return value_;
	}

private:
	std::string value_;
};

class IntLiteralToken: public Token
{
public:
	IntLiteralToken(int value) : Token(TOKEN_INT_LIT), value_(value) {}

	operator std::string() const
	{
		return "(INT_LIT, " + boost::lexical_cast<std::string>(value_) + ")";
	}

	int value() const
	{
		return value_;
	}

private:
	int value_;
};

class FloatLiteralToken: public Token
{
public:
	FloatLiteralToken(double value) : Token(TOKEN_FLOAT_LIT), value_(value) {}

	operator std::string() const
	{
		return "(FLOAT_LIT, " + boost::lexical_cast<std::string>(value_) + ")";
	}

	double value() const
	{
		return value_;
	}

private:
	double value_;
};

class BoolLiteralToken: public Token
{
public:
	BoolLiteralToken(bool value) : Token(TOKEN_BOOL_LIT), value_(value) {}

	operator std::string() const
	{
		return std::string("(BOOL_LIT, ") + (value_ ? "true" : "false" ) + ")";
	}

	bool value() const
	{
		return value_;
	}

private:
	bool value_;
};
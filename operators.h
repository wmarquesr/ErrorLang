#include "token.h"

class AssignSignToken: public Token
{
public:
	AssignSignToken() : Token(TOKEN_ASSIGN_SIGN) {}

	operator std::string() const
	{
		return "(ASSIGN_SIGN)";
	}
};

class PlusSignToken: public Token
{
public:
	PlusSignToken() : Token(TOKEN_PLUS_SIGN) {}

	operator std::string() const
	{
		return "(PLUS_SIGN)";
	}
};

class MinusSignToken: public Token
{
public:
	MinusSignToken() : Token(TOKEN_MINUS_SIGN) {}

	operator std::string() const
	{
		return "(MINUS_SIGN)";
	}
};

class MultiplySignToken: public Token
{
public:
	MultiplySignToken() : Token(TOKEN_MULTIPLY_SIGN) {}

	operator std::string() const
	{
		return "(MULTIPLY_SIGN)";
	}
};

class DivideSignToken: public Token
{
public:
	DivideSignToken() : Token(TOKEN_DIVIDE_SIGN) {}

	operator std::string() const
	{
		return "(DIVIDE_SIGN)";
	}
};

class ModulusSignToken: public Token
{
public:
	ModulusSignToken() : Token(TOKEN_MODULUS_SIGN) {}

	operator std::string() const
	{
		return "(MODULUS_SIGN)";
	}
};

class EqualsSignToken: public Token
{
public:
	EqualsSignToken() : Token(TOKEN_EQUALS_SIGN) {}

	operator std::string() const
	{
		return "(EQUALS_SIGN)";
	}
};

class NEqualsSignToken: public Token
{
public:
	NEqualsSignToken() : Token(TOKEN_NEQUALS_SIGN) {}

	operator std::string() const
	{
		return "(NEQUALS_SIGN)";
	}
};

class NegSignToken: public Token
{
public:
	NegSignToken() : Token(TOKEN_NEG_SIGN) {}

	operator std::string() const
	{
		return "(NEG_SIGN)";
	}
};

class AndToken: public Token
{
public:
	AndToken() : Token(TOKEN_AND) {}

	operator std::string() const
	{
		return "(AND)";
	}
};

class OrToken: public Token
{
public:
	OrToken() : Token(TOKEN_OR) {}

	operator std::string() const
	{
		return "(OR)";
	}
};

class LtSignToken: public Token
{
public:
	LtSignToken() : Token(TOKEN_LT_SIGN) {}

	operator std::string() const
	{
		return "(LT_SIGN)";
	}
};

class GtSignToken: public Token
{
public:
	GtSignToken() : Token(TOKEN_GT_SIGN) {}

	operator std::string() const
	{
		return "(GT_SIGN)";
	}
};

class LteSignToken: public Token
{
public:
	LteSignToken() : Token(TOKEN_LTE_SIGN) {}

	operator std::string() const
	{
		return "(LTE_SIGN)";
	}
};

class GteSignToken: public Token
{
public:
	GteSignToken() : Token(TOKEN_GTE_SIGN) {}

	operator std::string() const
	{
		return "(GTE_SIGN)";
	}
};
#ifndef ALCINOS_TOKEN_H
#define ALCINOS_TOKEN_H

#include <string>

enum TokenCategory{

	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_LBRACKET,
	TOKEN_RBRACKET,
	TOKEN_COMMA,
	TOKEN_SEMICOLON,

	TOKEN_ASSIGN_SIGN,
	TOKEN_PLUS_SIGN,
	TOKEN_MINUS_SIGN,
	TOKEN_MULTIPLY_SIGN,
	TOKEN_DIVIDE_SIGN,
	TOKEN_MODULUS_SIGN,
	TOKEN_EQUALS_SIGN,
	TOKEN_NEQUALS_SIGN,
	TOKEN_NEG_SIGN,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_LT_SIGN,
	TOKEN_GT_SIGN,
	TOKEN_LTE_SIGN,
	TOKEN_GTE_SIGN,

	TOKEN_STR_LIT,
	TOKEN_INT_LIT,
	TOKEN_FLOAT_LIT,
	TOKEN_BOOL_LIT,

	TOKEN_ID,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_BOOL,
    TOKEN_STRING,
    TOKEN_LIST,
    TOKEN_VOID,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_RETURN,
    TOKEN_WHILE

};

class Token
{
public:
	Token(TokenCategory category) : category_(category) {}
	virtual ~Token(){}

	TokenCategory category() const;

	virtual operator std::string() const = 0;

	int line;
	int lexpos;

protected:
	TokenCategory category_;
};

inline TokenCategory Token::category() const
{
	return category_;
}

#endif // ALCINOS_TOKEN_H
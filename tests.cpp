#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "lexer.h"
#include "type.h"
#include "literals.h"

using namespace std;
using namespace boost;

TEST(TokenizerTest, sample) {
	string source = "int var;\n"
		"var = 42;\r\n"
		"var = 53 * var\r"
		"if !( var > 3 ) && true && true != false {\n"
		"output ( \"blank generation\" ) ;\n"
		"}\n";

	stringstream stream(source);

	Lexer lexer(stream);

	shared_ptr<Token> token = lexer.nextToken();

	ASSERT_EQ(TOKEN_INT, token->category());
	ASSERT_EQ(1, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ID, token->category());
	ASSERT_EQ("var", static_pointer_cast<IdToken>(token)->value());
	ASSERT_EQ(1, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_SEMICOLON, token->category());
	ASSERT_EQ(1, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ID, token->category());
	ASSERT_EQ("var", static_pointer_cast<IdToken>(token)->value());
	ASSERT_EQ(2, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ASSIGN_SIGN, token->category());
	ASSERT_EQ(2, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_INT_LIT, token->category());
	ASSERT_EQ(42, static_pointer_cast<IntLiteralToken>(token)->value());
	ASSERT_EQ(2, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_SEMICOLON, token->category());
	ASSERT_EQ(2, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ID, token->category());
	ASSERT_EQ("var", static_pointer_cast<IdToken>(token)->value());
	ASSERT_EQ(3, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ASSIGN_SIGN, token->category());
	ASSERT_EQ(3, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_INT_LIT, token->category());
	ASSERT_EQ(53, static_pointer_cast<IntLiteralToken>(token)->value());
	ASSERT_EQ(3, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_MULTIPLY_SIGN, token->category());
	ASSERT_EQ(3, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ID, token->category());
	ASSERT_EQ("var", static_pointer_cast<IdToken>(token)->value());
	ASSERT_EQ(3, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_IF, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_NEG_SIGN, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_LPAREN, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ID, token->category());
	ASSERT_EQ("var", static_pointer_cast<IdToken>(token)->value());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_GT_SIGN, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_INT_LIT, token->category());
	ASSERT_EQ(3, static_pointer_cast<IntLiteralToken>(token)->value());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_RPAREN, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_AND, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_BOOL_LIT, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_AND, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_BOOL_LIT, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_NEQUALS_SIGN, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_BOOL_LIT, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_LBRACE, token->category());
	ASSERT_EQ(4, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ID, token->category());
	ASSERT_EQ("output", static_pointer_cast<IdToken>(token)->value());
	ASSERT_EQ(5, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_LPAREN, token->category());
	ASSERT_EQ(5, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_STR_LIT, token->category());
        ASSERT_EQ("blank generation",
                  static_pointer_cast<StringLiteralToken>(token)->value());
	ASSERT_EQ(5, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_RPAREN, token->category());
	ASSERT_EQ(5, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_SEMICOLON, token->category());
	ASSERT_EQ(5, token->line);

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_RBRACE, token->category());
	ASSERT_EQ(6, token->line);

	token = lexer.nextToken();

        ASSERT_EQ(false, bool(token));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

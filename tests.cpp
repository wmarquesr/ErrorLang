#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "lexer.h"
#include "type.h"
#include "literals.h"

using namespace std;
using namespace boost;

TEST(TokenizerTest, sample) {
	string source = "int var ;\n"
		"var = 42 ;\n"
		"var = 53 * var\n"
		"if ! ( var > 3 ) && true && true != false {\n"
		"output ( \"blank generation\" ) ;\n"
		"}\n";

	stringstream stream(source);

	Lexer lexer(stream);

	shared_ptr<Token> token = lexer.nextToken();

	ASSERT_EQ(TOKEN_INT, token->category());

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ID, token->category());
	ASSERT_EQ("var", static_pointer_cast<IdToken>(token)->value());

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_SEMICOLON, token->category());

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ID, token->category());
	ASSERT_EQ("var", static_pointer_cast<IdToken>(token)->value());

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_ASSIGN_SIGN, token->category());

	token = lexer.nextToken();

	ASSERT_EQ(TOKEN_INT_LIT, token->category());
	ASSERT_EQ(42, static_pointer_cast<IntLiteralToken>(token)->value());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
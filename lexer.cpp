#include "lexer.h"
#include "delim.h"
#include "operators.h"
#include "type.h"
#include "literals.h"
#include <boost/make_shared.hpp>
#include <boost/regex.hpp>
#include <cctype>

#include <iostream>

using namespace std;
using namespace boost;

/*bool isSingleCharToken(char ch)
{
	switch(ch) {
	case '(':
	case ')':
	case '[':
	case ']':
	case '{':
	case '}':
		return true;
	default:
		return false;
	}
}

bool isFirstHalfOfDoubleCharToken(char ch)
{
}

bool ifEndingHalfOfDoubleCharToken(char ch)
{
}*/

char lastStrChar(string str)
{
	return *(--str.end());
}

shared_ptr<Token> genToken(string str)
{
	if (str == "{")
		return make_shared<LBraceToken>();
	else if (str == "}")
		return make_shared<RBraceToken>();
	else if (str == "(")
		return make_shared<LParenToken>();
	else if (str == ")")
		return make_shared<RParenToken>();
	else if (str == "[")
		return make_shared<LBracketToken>();
	else if (str == "]")
		return make_shared<RBracketToken>();
	else if (str == ",")
		return make_shared<CommaToken>();
	else if (str == ";")
		return make_shared<SemiColonToken>();
	else if (str == "=")
		return make_shared<AssignSignToken>();
	else if (str == "+")
		return make_shared<PlusSignToken>();
	else if (str == "-")
		return make_shared<MinusSignToken>();
	else if (str == "*")
		return make_shared<MultiplySignToken>();
	else if (str == "/")
		return make_shared<DivideSignToken>();
	else if (str == "%")
		return make_shared<ModulusSignToken>();
	else if (str == "==")
		return make_shared<EqualsSignToken>();
	else if (str == "!=")
		return make_shared<NEqualsSignToken>();
	else if (str == "!")
		return make_shared<NegSignToken>();
	else if (str == "&&")
		return make_shared<AndToken>();
	else if (str == "||")
		return make_shared<OrToken>();
	else if (str == "<")
		return make_shared<LtSignToken>();
	else if (str == ">")
		return make_shared<GtSignToken>();
	else if (str == "<=")
		return make_shared<LteSignToken>();
	else if (str == ">=")
		return make_shared<GteSignToken>();
	else if (str == "int")
		return make_shared<IntToken>();
	else if (str == "float")
		return make_shared<FloatToken>();
	else if (str == "bool")
		return make_shared<BoolToken>();
	else if (str == "str")
		return make_shared<StringToken>();
	else if (str == "list")
		return make_shared<ListToken>();
	else if (str == "void")
		return make_shared<VoidToken>();
	else if (str == "if")
		return make_shared<IfToken>();
	else if (str == "else")
		return make_shared<ElseToken>();
	else if (str == "return")
		return make_shared<ReturnToken>();
	else if (str == "while")
		return make_shared<WhileToken>();
	else if (str == "true")
		return make_shared<BoolLiteralToken>(true);
	else if (str == "false")
		return make_shared<BoolLiteralToken>(false);
	else if (regex_match(str, regex("\"[^\"]*\"")))
		return make_shared<StringLiteralToken>(string(++str.begin(), --str.end()));
	else if (regex_match(str, regex("-?[0-9]+\\.[0-9]+")))
		return make_shared<FloatLiteralToken>(lexical_cast<double>(str));
	else if (regex_match(str, regex("-?[0-9]+")))
		return make_shared<IntLiteralToken>(lexical_cast<int>(str));
	else if (regex_match(str, regex("[a-zA-Z_][a-zA-Z_0-9]*")))
		return make_shared<IdToken>(str);
	else {
		cout << "####" << str << "####" << endl;
		throw SyntaxException();
	}
}

void eraseLastChar(string &str)
{
	str.erase(str.size() - 1);
}

shared_ptr<Token> Lexer::nextToken()
{
	if (buffer.size())
		return genToken(buffer);

	char_traits<char>::int_type ch;
	for (ch = in.get();;ch = in.get()) {
		if (ch == char_traits<char>::eof())
			break;

		++lexpos;

		// trata pulo de linha de forma multiplataforma
		// corrigir bug do mac que concatena dois tokens quando tem um espaço (\r) entre eles
		if (buffer.size() && lastStrChar(buffer) == '\r') {
			eraseLastChar(buffer);
			if (ch != '\n') {
				++line;
				lexpos = 0;
			}
		}

		if (ch == '\n') {
			++line;
			lexpos = 0;
		} else if (ch == '\r') {
			buffer += '\r';
			continue;
		}
		// fim de tratamento de linha

		// trata caso especial da string
		if (buffer.size()) {
			if (buffer[0] == '"') {
				buffer += ch;

				if (ch != '"')
					continue;

				shared_ptr<Token> token = genToken(buffer);
				token->line = line;
				token->lexpos = lexpos;
				buffer.clear();
				return token;
			}
		} else if (ch == '"') {
			buffer += ch;
			continue;
		}
		// fim do tratamento do caso especial da string

		if (isspace(ch)) {
			if (buffer.size()) {
				shared_ptr<Token> token = genToken(buffer);
				token->line = line;
				token->lexpos = lexpos;
				buffer.clear();
				return token;
			}
		} else {
			buffer += ch;
		}
	}
	if (buffer.size()) {
		shared_ptr<Token> token = genToken(buffer);
		token->line = line;
		token->lexpos = lexpos;
		buffer.clear();
		return token;
	} else {
		return shared_ptr<Token>();
	}
}
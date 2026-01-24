#include "Lexer.h"
#include <string>

using namespace std;

//Lexer::Lexer(const string& src)
//	: input(src), position((size_t)0), length(src.length()) {
//}

char Lexer::peek(int offset) const
{
	return input[position + offset];
}

char Lexer::advance()
{
	return input[position++];
}

bool Lexer::isAtEnd() const
{
	if(position >= length)
		return true;
	return false;
}

LinkedList<Token> Lexer::tokenize()
{
	// check spaces and skip them
	// tokenize numbers, variables, operators, parentheses
	// " 6 + 5 " -> [NUMBER(6), OPERATOR(+), NUMBER(5)]
	LinkedList<Token> tokens;
	while (!isAtEnd()) {
		char c = peek(); // get current character
		if (isspace(c)) {
			advance();
			continue;
		}
		if (isdigit(c)) {
			string numStr;
			while (isdigit(peek()) || peek() == '.') {
				numStr += advance();
			}
			tokens.addEnd(Token(TokenType::NUMBER, numStr));
			continue;
		}
		if (isalpha(c)) {
			tokens.addEnd(Token(TokenType::VARIABLE, string(1, c)));
			advance();
			continue;
		}
		switch (c) {
		case '+':
			tokens.addEnd(Token(TokenType::OPERATOR, string(1, c), 1)); advance(); break;
		case '-':
			tokens.addEnd(Token(TokenType::OPERATOR, string(1, c), 1)); advance(); break;
		case '*':
			tokens.addEnd(Token(TokenType::OPERATOR, string(1, c), 2)); advance(); break;
		case '/':
			tokens.addEnd(Token(TokenType::OPERATOR, string(1, c), 2)); advance(); break;
		case '^':
			tokens.addEnd(Token(TokenType::OPERATOR, string(1, c), 3)); advance(); break;
		case '(':
			tokens.addEnd(Token(TokenType::LPAREN, string(1, c))); advance(); break;
		case ')':
			tokens.addEnd(Token(TokenType::RPAREN, string(1, c))); advance(); break;
		default:
			cout << "Unknown character: " << c << endl; advance(); break;
		}
	}
	return tokens;
}

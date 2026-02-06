#include "Lexer.h"
#include <string>

using namespace std;

//Lexer::Lexer(const string& src)
//	: input(src), position((size_t)0), length(src.length()) {
//}

char Lexer::peek(int offset) const
{
	if(position + offset >= length)
		return '\0';
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
	// "-x+8" -> [NUMNER(-1), OPERATOR(*), VARIABLE(x), OPERATOR(+), NUMBER(8)]
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
			char nextChar = peek();
			if(isalpha(nextChar) || nextChar == '(') {
				tokens.addEnd(Token(TokenType::NUMBER, numStr));
				tokens.addEnd(Token(TokenType::OPERATOR, "*", 2));
				continue;
			}
			tokens.addEnd(Token(TokenType::NUMBER, numStr));
			continue;
		}
		if (isalpha(c)) {
			if (isdigit(peek(1))) {
				tokens.addEnd(Token(TokenType::OPERATOR, "*", 2));
			}
			tokens.addEnd(Token(TokenType::VARIABLE, string(1, c)));
			advance();
			continue;
		}
		switch (c) {
		case '+':
			tokens.addEnd(Token(TokenType::OPERATOR, string(1, c), 1)); advance(); break;
		case '-':{
			bool isUnary = false;
			if (tokens.isEmpty()) 
				isUnary = true;
			else {
				TokenType lastToken = tokens.peekBack().type;
				if(lastToken == TokenType::OPERATOR || lastToken == TokenType::LPAREN) {
					isUnary = true;
				}
			}

			if(isUnary) {
				tokens.addEnd(Token(TokenType::NUMBER, "-1"));
				tokens.addEnd(Token(TokenType::OPERATOR, "*", 2));
			}
			else {
				tokens.addEnd(Token(TokenType::OPERATOR, string(1, c), 1)); advance(); break;
			}

			advance(); 
			break;
		}
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

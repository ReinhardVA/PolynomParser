#pragma once
#include <string>
using namespace std;

enum class TokenType
{
	NUMBER, // 1, 3.5, 300
	VARIABLE, // x, y
	OPERATOR, // +, -, *, /
	LPAREN, // (
	RPAREN, // )
	UNKOWN, // Unknown token
	END_OF_INPUT, // End of input
};

struct Token
{
	TokenType type;
	string value;
	int precendence;
	int arguments;

	Token(TokenType t = TokenType::UNKOWN, const string& val = "", int prec = 0, int args = 0)
		: type(t), value(val), precendence(prec), arguments(args) {
	}
	string toString() const {

		switch (type) {
		case TokenType::NUMBER:
			return "NUMBER(" + value + ")";
		case TokenType::VARIABLE:
			return "VARIABLE(" + value + ")";
		case TokenType::OPERATOR:
			return "OPERATOR(" + value + ")";
		case TokenType::LPAREN:
			return "LPAREN"; 
		case TokenType::RPAREN:
			return "RPAREN"; 
		case TokenType::UNKOWN:
			return "UNKOWN"; 
		}
		return "END_OF_INPUT";
	};
	
	friend ostream& operator<<(ostream& os, const Token& token){
		os << token.toString();
		return os;
	}

	bool operator==(const Token& other) const {
		return type == other.type && value == other.value;
	}

};
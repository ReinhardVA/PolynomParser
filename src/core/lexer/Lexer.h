#pragma once
#include <string>
#include <DS/LinkedList.h>
#include "TokenType.h"
using namespace std;

class Lexer
{
private:
	string input;
	size_t position;
	int length;
	
	char peek(int offset = 0) const;
	char advance();
	bool isAtEnd() const;
public:
	Lexer(const string& src)
		: input(src), position(0), length(static_cast<int>(src.length())) {
	}

	LinkedList<Token> tokenize();
};


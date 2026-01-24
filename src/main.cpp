#include <iostream>
#include <vector>
#include <DS/Stack.h>
#include "core/lexer/Lexer.h"
#include <unordered_map>

using namespace std;
int main()
{
	string input = "3.5 + x^2 - 7 * x";
	cout << "Input Expression: " << input << endl;
	Lexer lexer(input);
	LinkedList<Token> tokens = lexer.tokenize();
	cout << "Tokens:" << endl;
	tokens.print();

    return 0;
}
#include <iostream>
#include <DS/Stack.h>
#include "core/lexer/Lexer.h"
#include "core/parser/ASTNode.h"
#include "core/parser/Parser.h"

using namespace std;

// Recursively print the AST with indentation
void printAST(ASTNode* node, string indent = "", bool isLast = true) {
	if (node == nullptr) return;

	cout << indent;
	// Create tree-like structure connectors
	if (isLast) {
		cout << "\\-";
		indent += "  ";
	}
	else {
		cout << "|-";
		indent += "| ";
	}

	// Identify and print specific node types
	if (auto num = dynamic_cast<NumberNode*>(node)) {
		cout << num->value << endl;
	}
	else if (auto var = dynamic_cast<VariableNode*>(node)) {
		cout << var->name << endl;
	}
	else if (auto op = dynamic_cast<OperatorNode*>(node)) {
		cout << op->operatorChar << endl;
		// Recursively print children
		printAST(op->left, indent, false);
		printAST(op->right, indent, true);
	}
}

int main()
{
	//string input = "3.5 + x^2 - 7 * x";
	string input = "3+5*2-8/4";
	cout << "Input Expression: " << input << endl;
	Lexer lexer(input);
	LinkedList<Token> tokens = lexer.tokenize();
	cout << "Tokens:" << endl;
	tokens.print();

	ASTNode* root = ParseToAST(tokens);
	if (root) {
		cout << "AST Structure: " << root << endl;
		printAST(root);
	}

    return 0;
}
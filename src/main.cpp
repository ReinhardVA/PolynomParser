#include <iostream>
#include <DS/Stack.h>
#include "core/lexer/Lexer.h"
#include "core/parser/ASTNode.h"
#include "core/parser/Parser.h"
#include "core/evaluator/Evaluator.h"

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
	//string input = "3+5*2-8/4";
	/*string input = "(12 + 2) * (2x) / 4";*/
	//string input = "x3 + 4";
	string input = "-3x + 5";
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
	Evaluator evaluator;
	for(int i = 0; i < 5; i++) {
		double result = evaluator.EvaluateExpression(root, static_cast<double>(i));
		cout << "Evaluation with x=" << i << ": " << result << endl;
	}

	delete root;

    return 0;
}


// Problems:
// 1. Negative numbers are not handled correctly. 
// For example, the expression "-3 + 5" is tokenized as OPERATOR(-) NUMBER(3) OPERATOR(+) NUMBER(5), which leads to incorrect parsing and evaluation.
// The lexer should be modified to recognize negative numbers as a single token, or the parser should be adjusted to handle unary operators properly.
// eğer bir sayıdan önce - operatörü gelirse ve arada boşluk yoksa
// bu iki token arasında bir NEGATIVE tokenı eklenebilir veya mevcut OPERATOR(-) tokenı NEGATIVE olarak işaretlenebilir.
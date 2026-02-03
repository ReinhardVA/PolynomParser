#pragma once
#include <string>
using namespace std;
struct ASTNode
{
	virtual ~ASTNode() = default;
};

struct NumberNode : public ASTNode
{
	double value;
	NumberNode(double val) : value(val) {}
};

struct VariableNode : public ASTNode
{
	char name;
	int value = 0;
	VariableNode(char varName) : name(varName) {}
	double increaseValue() {
		return ++value;
	}
};

struct OperatorNode : public ASTNode {
	char operatorChar;
	ASTNode* left;
	ASTNode* right;
	OperatorNode(char op, ASTNode* l, ASTNode* r)
		: operatorChar(op), left(l), right(r) {
	}
	~OperatorNode() {
		delete left;
		delete right;
	}

};
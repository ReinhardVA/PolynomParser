#pragma once
#include "../parser/ASTNode.h"
class Evaluator
{
public:
	double EvaluateExpression(ASTNode* root, double xValue);
};


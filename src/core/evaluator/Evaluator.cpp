#include "Evaluator.h"
#include <stdexcept>

double Evaluator::EvaluateExpression(ASTNode* root, double xValue)
{
	if (root == nullptr) return 0.0;

	if (auto* numNode = dynamic_cast<NumberNode*>(root)) {
		return numNode->value;
	}

	if (auto* varNode = dynamic_cast<VariableNode*>(root)) {
		if (varNode->name == 'x') {
			return xValue;
		}
	}

	if (auto* opNode = dynamic_cast<OperatorNode*>(root)) {
		double leftVal = EvaluateExpression(opNode->left, xValue);
		double rightVal = EvaluateExpression(opNode->right, xValue);

		switch (opNode->operatorChar) {
			case '+':
				return leftVal + rightVal;
			case '-':
				return leftVal - rightVal;
			case '*':
				return leftVal * rightVal;
			case '/':
				if(rightVal == 0) {
					throw std::runtime_error("Division by zero");
				}
				return leftVal / rightVal;
			case '^':
				return pow(leftVal, rightVal);
			default:
				return 0.0; // Unsupported operator
		}
	}
	return 0.0; // Default case for unsupported node types
}

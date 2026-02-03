#include "Parser.h"
#include <DS/LinkedList.h>
#include <DS/Stack.h>
#include "../lexer/TokenType.h"
#include "ASTNode.h"

using namespace std;

void CombineNodes(Stack<Token>& operatorStack, Stack<ASTNode*>& nodeStack);

ASTNode* ParseToAST(LinkedList<Token>& tokens) {
	
	Stack<ASTNode*> nodeStack;
	Stack<Token> operatorStack;

	for (const auto& token : tokens) {
		// shunting yard algorithm to convert to AST
		if (token.type == TokenType::NUMBER) {
			nodeStack.push(new NumberNode(stod(token.value)));
		}
		else if(token.type == TokenType::VARIABLE) {
			nodeStack.push(new VariableNode(token.value[0]));
		}
		else if (token.type == TokenType::OPERATOR) {
			while (!operatorStack.isEmpty()) {
				if (operatorStack.top().precendence >= token.precendence) {
					CombineNodes(operatorStack, nodeStack);
				}
				else {
					break;
				}
			}
			operatorStack.push(token);
		}
		else if (token.type == TokenType::LPAREN) {
			operatorStack.push(token);
		}
		else if (token.type == TokenType::RPAREN) {
			while (operatorStack.top().type != TokenType::LPAREN) {
				CombineNodes(operatorStack, nodeStack);
			}
			operatorStack.pop();
		}
	}

	while (!operatorStack.isEmpty()) {
		CombineNodes(operatorStack, nodeStack);
	}

	return nodeStack.top();
}

void CombineNodes(Stack<Token>& operatorStack, Stack<ASTNode*>& nodeStack)
{
	Token topOperator = operatorStack.top();
	operatorStack.pop();
	ASTNode* right = nodeStack.top();
	nodeStack.pop();
	ASTNode* left = nodeStack.top();
	nodeStack.pop();

	nodeStack.push(new OperatorNode(topOperator.value[0], left, right));
}

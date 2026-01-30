#include "Parser.h"
#include "src/ast/ASTNode.h"
#include "src/core/lexer/TokenType.h"
#include <DS/LinkedList.h>
#include <DS/Stack.h>

ASTNode* ParseToAST(LinkedList<Token>& tokens) {
	
	Stack<ASTNode*> nodeStack;
	Stack<Token> operatorStack;

	for (const auto& token : tokens) {

	}
}
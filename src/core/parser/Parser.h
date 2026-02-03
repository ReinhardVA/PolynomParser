#pragma once
#include <DS/LinkedList.h>
#include "../lexer/TokenType.h"
#include "ASTNode.h"

ASTNode* ParseToAST(LinkedList<Token>& tokens);

class Parser
{
};


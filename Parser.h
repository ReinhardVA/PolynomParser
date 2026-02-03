#pragma once
#include <DS/LinkedList.h>
#include "src/ast/ASTNode.h"
#include "src/core/lexer/TokenType.h"


ASTNode* ParseToAST(LinkedList<Token>& tokens);

class Parser
{
};


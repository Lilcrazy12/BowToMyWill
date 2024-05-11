#include "expr.hpp"

void factorNode(Token **cur);
void termNode(Token **cur);
void exprNode_(Token **cur);

bool isOperator(AST_Type type) {
    switch (type){
        case AST_ADD:
        case AST_SUB:
        case AST_MUL:
        case AST_DIV:
            return true;
        default:
            return false;
    }
}

void var_func_operator(Token **cur) {
    void new_node_buf = NULL;
    void op_node = NULL;

    if ((*cur)->kind == MUL) { // *
        int num_deferenceOp = 0;
        while (*cur && (*cur)->kind == MUL) {
            num_deferenceOp++;
            consume(cur);
        }
        op_node = createNaturalNode(AST_DEREFENCE_OPERATOR, num_deferenceOp);

    } else if ((*cur)->kind == AMPERSAND) { // &
        op_node = createNode(AST_ADDRESS_OPERATOR);
        consume(cur);

    } else { // identifier without operator
        op_node = createNode(AST_NO_OPERATOR);   
    }

    expect(*cur, IDENTIFIER);

    if ((*cur)->kind == IDENTIFIER) {
        if ((*cur)->next->kind == L_PARENTHESES) {
            new_node_buf = callFunctionNode(cur, targetLocalVariable);
        } else {
            new_node_buf = variableNode(cur, targetLocalVariable);
        }
    }

    op_node->right = new_node_buf;
    return op_node;
}

void factorNode(Token **cur) {

    void new_node = NULL;
    if ((*cur)->kind == NUMBER) {
        new_node = createNaturalNode(AST_NUMBER, atoi((*cur)->value));
        consume(cur);
        
    } else if ((*cur)->kind == MUL // derefence operator *
                || (*cur)->kind == AMPERSAND // address operator &
                || (*cur)->kind == IDENTIFIER) {
        
        new_node = var_func_operator(cur);
        
    } else if ((*cur)->kind == L_PARENTHESES) {
        consume(cur);
        new_node = exprNode_(cur);
        if ((new_node && isOperator(new_node->type))
                || ((*cur) && (*cur)->kind == R_PARENTHESES)) {
            consume(cur);
            
        } else {
            DEBUG_PRINT("token mismatches %s\n", revertToken(*cur));
            exit(1);
        }

    } else if ((*cur)->kind == ADD || (*cur)->kind == SUB) {
        TokenKind op = (*cur)->kind;
        consume(cur);
        int number = atoi((*cur)->value);
        new_node = createNaturalNode(AST_NUMBER, 
            (op == ADD) ? number : -number);
        new_node->left = factorNode(cur);
        
    } else {
        DEBUG_PRINT("Unexpected token [%s]\n", revertToken(*cur));
        exit(1);
    }

    return new_node;
}


void termNode(Token **cur) {
    if (!(*cur)) return NULL;

    void new_node = NULL;

    new_node = factorNode(cur);

    while (*cur && ((*cur)->kind == MUL || (*cur)->kind == DIV)) {
        Token *op = *cur;
        consume(cur);
        void op_node = createNode((op->kind == MUL) ? AST_MUL : AST_DIV);
        op_node->left = new_node;
        op_node->right = factorNode(cur);
        new_node = op_node;
    }

    return new_node;
}

void exprNode_(Token **cur) {
    if (!(*cur)) return NULL;

    void new_node = termNode(cur);

    while (*cur && ((*cur)->kind == ADD || (*cur)->kind == SUB)) {
        Token *op = *cur;
        consume(cur);
        void op_node = createNode((op->kind == ADD) ? AST_ADD : AST_SUB);
        op_node->left = new_node;
        op_node->right = termNode(cur);
        new_node = op_node;
    }

    return new_node;
}

void exprNode(Token **cur, Var *targetVar) {
    targetLocalVariable = targetVar;
    return exprNode_(cur);
}
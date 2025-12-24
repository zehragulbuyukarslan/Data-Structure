/* Derleyiciler (Compilers)
 Programlama dillerinin derleyicileri, kod yapisini temsil etmek icin **Abstract Syntax Tree (AST)** kullanir.
Ornek: 'a = b + c * 2' ifadesi icin AST:
       =
      / \
     a   +
        / \
       b   *
           /\
          c 2 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_OP,
    NODE_ID,
    NODE_NUM
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char op;                 // NODE_OP icin: '+', '*', '=' gibi
    char id[32];             // NODE_ID iciin: "a", "b", "c"
    int num;                 // NODE_NUM icin: 2 gibi
    struct ASTNode *left;
    struct ASTNode *right;
} ASTNode;

ASTNode* newOp(char op, ASTNode* left, ASTNode* right) {
    ASTNode* n = (ASTNode*)malloc(sizeof(ASTNode));
    n->type = NODE_OP;
    n->op = op;
    n->id[0] = '\0';
    n->num = 0;
    n->left = left;
    n->right = right;
    return n;
}

ASTNode* newId(const char* name) {
    ASTNode* n = (ASTNode*)malloc(sizeof(ASTNode));
    n->type = NODE_ID;
    n->op = '\0';
    strncpy(n->id, name, sizeof(n->id) - 1);
    n->id[sizeof(n->id) - 1] = '\0';
    n->num = 0;
    n->left = n->right = NULL;
    return n;
}

ASTNode* newNum(int value) {
    ASTNode* n = (ASTNode*)malloc(sizeof(ASTNode));
    n->type = NODE_NUM;
    n->op = '\0';
    n->id[0] = '\0';
    n->num = value;
    n->left = n->right = NULL;
    return n;
}

void printNode(ASTNode* n) {
    if (!n) return;
    if (n->type == NODE_OP) printf("%c", n->op);
    else if (n->type == NODE_ID) printf("%s", n->id);
    else printf("%d", n->num);
}

void preorder(ASTNode* root) { // root-left-right
    if (!root) return;
    printNode(root); printf(" ");
    preorder(root->left);
    preorder(root->right);
}

void inorder(ASTNode* root) { // left-root-right (ifade gibi)
    if (!root) return;
    if (root->type == NODE_OP) printf("(");
    inorder(root->left);
    printNode(root); printf(" ");
    inorder(root->right);
    if (root->type == NODE_OP) printf(")");
}

void postorder(ASTNode* root) { // left-right-root
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printNode(root); printf(" ");
}

// Aðacý yan çiz (sað çocuk üstte görünür)
void printTree(ASTNode* root, int depth) {
    if (!root) return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("    ");
    printNode(root);
    printf("\n");
    printTree(root->left, depth + 1);
}

void freeTree(ASTNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    // a = b + c * 2
    // Önce: c * 2
    ASTNode* mult = newOp('*', newId("c"), newNum(2));

    // Sonra: b + (c*2)
    ASTNode* plus = newOp('+', newId("b"), mult);

    // En son: a = (b + c*2)
    ASTNode* assign = newOp('=', newId("a"), plus);

    printf("AST (sideways):\n");
    printTree(assign, 0);

    printf("\nPreorder : ");
    preorder(assign);

    printf("\nInorder  : ");
    inorder(assign);

    printf("\n\nPostorder: ");
    postorder(assign);

    printf("\n");

    freeTree(assign);
    return 0;
}

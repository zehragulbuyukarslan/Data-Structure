// week-7 pre order 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void preorder(Node* root) {          // Root, Left, Right
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {           // Left, Root, Right
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {         // Left, Right, Root
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Basit level-order için kuyruk:
typedef struct {
    Node* arr[100];
    int front, rear;
} Queue;

void qinit(Queue* q){ q->front = q->rear = 0; }
int qempty(Queue* q){ return q->front == q->rear; }
void push(Queue* q, Node* x){ q->arr[q->rear++] = x; }
Node* pop(Queue* q){ return q->arr[q->front++]; }

void levelorder(Node* root) {
    if (!root) return;
    Queue q; qinit(&q);
    push(&q, root);
    while (!qempty(&q)) {
        Node* cur = pop(&q);
        printf("%d ", cur->data);
        if (cur->left) push(&q, cur->left);
        if (cur->right) push(&q, cur->right);
    }
}

int main() {
    // Resimdeki aðacý kur:
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Preorder   : "); preorder(root);   printf("\n");
    printf("Inorder    : "); inorder(root);    printf("\n");
    printf("Postorder  : "); postorder(root);  printf("\n");
    printf("Level-order: "); levelorder(root); printf("\n");

    return 0;
}

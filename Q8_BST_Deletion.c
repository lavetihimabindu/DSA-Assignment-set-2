#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int x) {
    Node *n = malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed.\\n"); exit(1); }
    n->data = x; n->left = n->right = NULL; return n;
}
Node *insert(Node *r, int x) {
    if (!r) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}
void inorder(Node *r) {
    if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); }
}
Node *minimum(Node *r) { while (r && r->left) r = r->left; return r; }
Node *deleteNode(Node *r, int key) {
    if (!r) return NULL;
    if (key < r->data) r->left = deleteNode(r->left, key);
    else if (key > r->data) r->right = deleteNode(r->right, key);
    else {
        if (!r->left) { Node *t = r->right; free(r); return t; }
        if (!r->right) { Node *t = r->left; free(r); return t; }
        Node *s = minimum(r->right);
        r->data = s->data;
        r->right = deleteNode(r->right, s->data);
    }
    return r;
}
void freeTree(Node *r) { if (r) { freeTree(r->left); freeTree(r->right); free(r); } }

int main(void) {
    Node *root = NULL; int n, x, key;
    printf("Enter number of nodes: "); scanf("%d", &n);
    if (n < 1 || n > 1000) { printf("Invalid number of nodes.\\n"); return 1; }
    printf("Enter unique values: ");
    for (int i = 0; i < n; i++) { scanf("%d", &x); root = insert(root, x); }
    printf("Inorder before deletion: "); inorder(root); printf("\\n");
    printf("Enter node to delete: "); scanf("%d", &key);
    root = deleteNode(root, key);
    printf("Inorder after deletion: "); inorder(root); printf("\\n");
    freeTree(root);
    return 0;
}

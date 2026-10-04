#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *insert(Node *root, int value) {
    if (!root) {
        Node *n = malloc(sizeof(Node));
        if (!n) { printf("Memory allocation failed.\\n"); exit(1); }
        n->data = value; n->left = n->right = NULL;
        return n;
    }
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}
void inorder(Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void preorder(Node *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }
int search(Node *r, int key) {
    while (r) {
        if (key == r->data) return 1;
        r = key < r->data ? r->left : r->right;
    }
    return 0;
}
void freeTree(Node *r) { if (r) { freeTree(r->left); freeTree(r->right); free(r); } }

int main(void) {
    Node *root = NULL; int n, value, key;
    printf("Enter number of values: "); scanf("%d", &n);
    if (n < 1 || n > 1000) { printf("Invalid number of values.\\n"); return 1; }
    printf("Enter %d unique values: ", n);
    for (int i = 0; i < n; i++) { scanf("%d", &value); root = insert(root, value); }
    printf("Inorder: "); inorder(root); printf("\\n");
    printf("Preorder: "); preorder(root); printf("\\n");
    printf("Postorder: "); postorder(root); printf("\\n");
    printf("Enter value to search: "); scanf("%d", &key);
    printf("%d %s in the BST.\\n", key, search(root, key) ? "exists" : "does not exist");
    printf("Inorder is sorted because each node's left subtree has smaller values and its right subtree has larger values.\\n");
    freeTree(root);
    return 0;
}

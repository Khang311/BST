#ifndef BST_H
#define BST_H


typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;


typedef struct Tree
{
    Node *root;
} Tree;

Node *createNode(int value);
Tree *createTree(void);
int tree_insert(Tree *tree, int value);
void tree_print_inorder(const Tree *tree);
int size(Node *root);
int countLeaves(Node *root);
int max(Node *root);
#endif
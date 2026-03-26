#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node *createNode(int value)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr,"Memory allocation failure!\n");
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree *createTree(void)
{
    Tree *tree = malloc(sizeof(Tree));
    if (tree == NULL)
    {
        fprintf(stderr,"Memory allocation failure!\n");
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

int tree_insert(Tree *tree, int value)
{
    if (tree == NULL) return 0;
    Node *newNode = createNode(value);

    if (tree->root == NULL)
    {
        tree->root = newNode;
        return 1;
    }
    Node *current = tree->root;
    Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (value == current->value) return 1;
        else if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }
    
    if (value < parent->value)
    {
        parent->left = newNode;
    }
    else parent->right = newNode;
    
    return 1;
}

void inorder_traverse(const Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder_traverse(node->left);
    printf("%d ", node->value);
    inorder_traverse(node->right);
}

void tree_print_inorder(const Tree *tree)
{
    inorder_traverse(tree->root);
}

int size(Node *root)
{
    if (root == NULL) return 0;

    int leftSize = size(root->left);
    int rightSize = size(root->right);
    
    return 1 + leftSize + rightSize;
}

int countLeaves(Node *root)
{

    if(root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;

    int leftLeaves = countLeaves(root->left);
    int rightLeaves = countLeaves(root->right);
    
    return leftLeaves + rightLeaves;
}

int max(Node *root)
{
    if(root->right == NULL) return root->value;
    else return max(root->right);
}

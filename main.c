#include "bst.h"
#include <stdio.h>

int main(void)
{
    Tree *tree = createTree();
    if (!tree)
        return 1;

    tree_insert(tree, 2);
    tree_insert(tree, 5);
    tree_insert(tree, 4);
    tree_insert(tree, 10);
    tree_insert(tree, 7);
    tree_insert(tree, 1);
    tree_insert(tree, 67);

    printf("Tree in order: ");
    tree_print_inorder(tree);

    // c1
    int tree_size = size(tree->root);
    printf("\nSize of tree: %d", tree_size);

    // c2
    int leaves = countLeaves(tree->root);
    printf("\nNumber of leaves: %d", leaves);

    // c3
    int tree_max = max(tree->root);
    printf("\nTree max: %d", tree_max);
}
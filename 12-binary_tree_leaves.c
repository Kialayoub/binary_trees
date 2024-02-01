#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: The number of leaves in the tree. If tree is NULL, return 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t leaves = 0;

    if (tree)
    {
        if (!tree->left && !tree->right)
        {
            leaves += 1;
        }
        else
        {
            leaves += binary_tree_leaves(tree->right);
            leaves += binary_tree_leaves(tree->left);
        }
    }

    return (leaves);
}

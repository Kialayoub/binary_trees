#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_nodes - Counts the nodes with at least one child in a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: The number of nodes with at least one child in the tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t nodes = 0;

    if (tree)
    {
        if (tree->left || tree->right)
        {
            nodes += 1;
        }
        
        nodes += binary_tree_nodes(tree->right);
        nodes += binary_tree_nodes(tree->left);
    }

    return (nodes);
}

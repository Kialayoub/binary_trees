#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: A pointer to the root node of the tree
 * Return: 1 if full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
    /* If the tree is empty */
    if (tree == NULL)
        return (0);

    /* If it's a leaf */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* If one subtree is empty while the other is not*/
    if (tree->left && tree->right)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
    
    /* If the tree is not empty  */
    return (0);
}

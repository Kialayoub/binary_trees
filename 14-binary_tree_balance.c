#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: The balance factor of the tree.
 * If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree)
        return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
    else
        return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 * If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t l = 0, r = 0;

        if (tree->left)
            l = 1 + binary_tree_height(tree->left);
        else
            l = 1;

        if (tree->right)
            r = 1 + binary_tree_height(tree->right);
        else
            r = 1;

        return ((l > r) ? l : r);
    }
    else
    {
        return (0);
    }
}

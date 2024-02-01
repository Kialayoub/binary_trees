#include <stdlib.h>
#include "binary_trees.h"

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 * Return: If the node is a leaf, 1, 0 otherwise.
 */

unsigned char is_leaf(const binary_tree_t *node)
{
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return 0;
}

/**
 * tree_depth - Returns the depth of a given node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 * Return: The depth of the node.
 */

size_t tree_depth(const binary_tree_t *tree)
{
    if (tree->parent != NULL)
        return 1 + tree_depth(tree->parent);
    else
        return 0;
}

/**
 * find_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node.
 * Return: A pointer to the first encountered leaf.
 */

const binary_tree_t *find_leaf(const binary_tree_t *tree)
{
    if (is_leaf(tree))
        return tree;
    else
    {
        if (tree->left)
            return find_leaf(tree->left);
        else
            return find_leaf(tree->right);
    }
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of the current node.
 * Return: If the tree is perfect retunr 1, 0 otherwise.
 */

int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth, size_t level)
{
    if (is_leaf(tree))
    {
        if (level == leaf_depth)
            return 1;
        else
            return 0;
    }
    else
    {
        if (tree->left == NULL || tree->right == NULL)
            return 0;
        else
            return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
                    is_perfect_recursive(tree->right, leaf_depth, level + 1));
    }
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or not perfect return 0. 1 Otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return is_perfect_recursive(tree, tree_depth(find_leaf(tree)), 0);
}

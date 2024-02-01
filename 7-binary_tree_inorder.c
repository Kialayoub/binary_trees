#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node node value as a parameter
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
  /* Check if the tree and function are not NULL */
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}

}

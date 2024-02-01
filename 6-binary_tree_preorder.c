#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a pre-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node node value as a parameter
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}

}

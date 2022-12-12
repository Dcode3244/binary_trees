#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through binary tree using
 * the pre-order traversal
 * @tree: pointer to the root node of the tree to be traversed
 * @func: pointer to a function to call for each node
 * the value in the node must be passed as a parameter to this funciton
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

#include "binary_trees.h"
#include <limits.h>

int is_bst(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary search tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}


/**
 * is_bst - checks if a binary tree is a valid Binary search tree
 * @tree: pointer to the root node of the tree to check
 * @min: the minimum value the node can hold
 * @max: the maximum value the node can hold
 * Return: 1 if tree is a valid BST, otherwise 0
 */

int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		return (is_bst(tree->left, min, tree->n - 1) &&
				is_bst(tree->right, tree->n + 1, max));
	}
	return (1);
}

#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation on a binary tree
 * @tree: pointer to the root node of the tree to be ckecked
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *r;

	if (tree == NULL)
		return (NULL);
	r = tree->right;

	r->parent = tree->parent;
	tree->right = r->left;

	if (r->left)
		r->left->parent = tree;

	tree->parent = r;
	r->left = tree;

	if (r->parent)
	{
		if (r->parent->left == tree)
			r->parent->left = r;
		else
			r->parent->right = r;
	}
	return (r);
}

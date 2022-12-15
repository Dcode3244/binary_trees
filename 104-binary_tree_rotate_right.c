#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right rotation on a binary tree
 * @tree: pointer to the root node of the tree to be ckecked
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *l;

	if (tree == NULL)
		return (NULL);
	l = tree->left;

	l->parent = tree->parent;
	tree->left = l->right;

	if (l->right)
		l->right->parent = tree;

	tree->parent = l;
	l->right = tree;

	if (l->parent)
	{
		if (l->parent->left == tree)
			l->parent->left = l;
		else
			l->parent->right = l;
	}
	return (l);
}

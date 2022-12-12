#include "binary_trees.h"

size_t tree_height(const binary_tree_t *tree);
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the binary tree
 * Return: height of the binary tree or
 * 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_height(tree) - 1);
}

/**
 * tree_height - measures the height of the binary tree
 * @tree: pointer to the root node of the binary tree
 * Return: height of the binary tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

#include "binary_trees.h"

int binary_tree_h(const binary_tree_t *tree);
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to be measured
 * Return: balance factor of the tree, or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_h(tree->left);
	right = binary_tree_h(tree->right);

	return (left - right);
}

/**
 * binary_tree_h - measures the height of the binary tree
 * @tree: pointer to the root node of the tree to be measured
 * Return: height of the binary tree
 */
int binary_tree_h(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_h(tree->left);
	right = binary_tree_h(tree->right);

	if (left < right)
		return (right + 1);
	else
		return (left + 1);
}

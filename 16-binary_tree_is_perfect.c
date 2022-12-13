#include "binary_trees.h"

int binary_tree_perfect(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the rooot node of the tree to be checked
 * Return: 1 if binary tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_perfect(tree->left);
	right = binary_tree_perfect(tree->right);

	return (left == right ? 1 : 0);
}

/**
 * binary_tree_perfect - checks if a binary tree is perfect
 * @tree: pointer to the rooot node of the tree to be checked
 * Return: 1 if binary tree is perfect, else 0
 */
int binary_tree_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_perfect(tree->left);
	right = binary_tree_perfect(tree->right);

	return (left + right + 1);
}

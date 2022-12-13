#include "binary_trees.h"

int binary_tree_full(const binary_tree_t *tree);
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to be ckecked
 * Return: 1 if tree is full, else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_full(tree));
}

/**
 * binary_tree_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to be checkerd
 * Return: 1 if full, else 0
 */
int binary_tree_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if ((tree->left != NULL && tree->right == NULL)
			|| (tree->left == NULL && tree->right != NULL))
		return (0);

	left = binary_tree_full(tree->left);
	right = binary_tree_full(tree->right);

	if (left == 0 || right == 0)
		return (0);
	return (1);
}

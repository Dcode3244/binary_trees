#include "binary_trees.h"
#include <math.h>
#include <limits.h>

int height(const binary_tree_t *tree);
int is_avl(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_avl - checks if tree is a valid AVL tre
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is valid AVK tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX));

}

/**
 * is_avl - checks if tree is a valid AVL tre
 * @tree: pointer to the root node of the tree to check
 * @min: minimum possible value of a node value
 * @max: maximum possible value of a node value
 * Return: 1 if tree is valid AVK tree, otherwise 0
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	if (abs(left - right) <= 1 && is_avl(tree->left, min, tree->n - 1)
			&& is_avl(tree->right, tree->n + 1, max))
		return (1);
	return (0);

}

/**
 * height - measures the height of the binary tree
 * @tree: pointer to the root node of the tree to check
 * Return: height of the binary tree
 */
int height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

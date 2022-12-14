#include "binary_trees.h"

void print_current_level(binary_tree_t *tree, int level, void (*func)(int));
int height(binary_tree_t *node);
/**
 * binary_tree_levelorder - goes through binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, h;

	h = height((binary_tree_t *)tree) - 1;

	for (i = 0; i <= h; i++)
		print_current_level((binary_tree_t *)tree, i, func);
}

/**
 * print_current_level - prints the tree in level order
 * @tree: pointer to the root node of the binary tree
 * @level: the level to be printed
 * @func: pointer to a function to call for each node
 */
void print_current_level(binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		print_current_level(tree->left, level - 1, func);
		print_current_level(tree->right, level - 1, func);
	}
}

/**
 * height - measures the height of the binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: the height of the binary tree
 */
int height(binary_tree_t *tree)
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

#include "binary_trees.h"

void traverse_right(const binary_tree_t *tree, void (*func)(int));
void traverse_left(const binary_tree_t *tree, void (*func)(int));
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
	if (tree->left)
		traverse_left(tree->left, func);

	if (tree->right)
		traverse_right(tree->right, func);
}

/**
 * traverse_left - goes through left side of binary tree
 * @tree: the tree to be traversed
 * @func: pointer to a function to call for each node
 */
void traverse_left(const binary_tree_t *tree, void (*func)(int))
{
	func(tree->n);

	if (tree->left)
		traverse_left(tree->left, func);
	if (tree->right)
		traverse_right(tree->right, func);

}

/**
 * traverse_right - goes through right side of binary tree
 * @tree: the tree to be traversed
 * @func: pointer to a function to call for each node
 */
void traverse_right(const binary_tree_t *tree, void (*func)(int))
{
	func(tree->n);

	if (tree->left)
		traverse_left(tree->left, func);
	if (tree->right)
		traverse_right(tree->right, func);
}

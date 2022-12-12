#include "binary_trees.h"

void delete_right(binary_tree_t *tree);
void delete_left(binary_tree_t *tree);
/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	if (tree->right)
		delete_right(tree->right);

	if (tree->left)
		delete_left(tree->left);

	free(tree);
}

/**
 * delete_right - deletes right side of the tree
 * @tree: the binary tree
 */
void delete_right(binary_tree_t *tree)
{
	if (tree->right)
		delete_right(tree->right);

	if (tree->left)
		delete_left(tree->left);

	free(tree);
}

/**
 * delete_left - deletes left side of the tree
 * @tree: the binary tree
 */
void delete_left(binary_tree_t *tree)
{
	if (tree->right)
		delete_right(tree->right);

	if (tree->left)
		delete_left(tree->left);

	free(tree);
}


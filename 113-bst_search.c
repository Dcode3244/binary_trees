#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containin ga value equals to value
 * or NULL if tree is NULL or if notting is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);
	else if (tree->n > value)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}

#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: pointer to the first element of the array to be convertes
 * @size: the number of elements in the array
 * Return: pointer to the root node of the created BST, or
 * NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree, *node;

	if (array == NULL)
		return (NULL);

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		node = bst_insert(&tree, array[i]);
		if (node == NULL)
			return (NULL);
	}
	return (tree);
}

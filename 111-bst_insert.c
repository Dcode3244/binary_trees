#include "binary_trees.h"

bst_t *insert(bst_t *tree, bst_t *new);
/**
 * bst_insert - inserts a value in a binary search tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: pointer to the created node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *temp = *tree;

	if (!(*tree) || !tree)
	{
		new = binary_tree_node(NULL, value);
		if (new == NULL)
			return (NULL);
		*tree = new;
		return (*tree);
	}
	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);

	while (temp)
	{
		if (temp->n > new->n)
		{
			if (temp->left == NULL)
			{
				temp->left = new;
				new->parent = temp;
				return (new);
			}
			temp = temp->left;
		}
		else if (temp->n < new->n)
		{
			if (temp->right == NULL)
			{
				temp->right = new;
				new->parent = temp;
				return (new);
			}
			temp = temp->right;
		}
		else
			return (NULL);
	}
	return (NULL);
}

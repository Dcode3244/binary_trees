#include "binary_trees.h"

int node_depth(const binary_tree_t *node);
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node or
 * NULL if no ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int dfirst, dsecond;

	if ((first == NULL || first->parent == NULL) ||
			(second == NULL || second->parent == NULL))
		return (NULL);

	dfirst = node_depth(first);
	dsecond = node_depth(second);

	for (; dfirst < dsecond; dsecond--)
		second = second->parent;

	for (; dfirst > dsecond; dfirst--)
		first = first->parent;

	do {
		if (first == second)
		{
			first = first->left;
			return (first->parent);
		}
			first = first->parent;
		second = second->parent;
	} while (first != NULL);

	return (NULL);
}

/**
 * node_depth - finds the depthi of a node in a binary tree
 * @node: a node of a binary tree
 * Return: the depth of the binary tree node
 */
int node_depth(const binary_tree_t *node)
{
	int depth;
	binary_tree_t temp;

	temp = *node;

	for (depth = 0; temp.parent; depth++)
		temp = *(temp.parent);

	return (depth);
}

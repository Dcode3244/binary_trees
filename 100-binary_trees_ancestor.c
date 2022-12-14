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
	binary_tree_t *f_parent, *s_parent;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	f_parent = first->parent;
	s_parent = second->parent;
	if (first == s_parent || !f_parent || (!f_parent->parent && s_parent))
		return (binary_trees_ancestor(first, s_parent));

	if (second == f_parent || !s_parent || (!s_parent->parent && f_parent))
		return (binary_trees_ancestor(f_parent, second));

	return (binary_trees_ancestor(f_parent, s_parent));
}

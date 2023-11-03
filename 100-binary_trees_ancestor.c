#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *node1 = (binary_tree_t *)first;
	binary_tree_t *node2 = (binary_tree_t *)second;
	binary_tree_t *ancestor1, *ancestor2;

	if (!node1 || !node2)
		return (NULL);

	ancestor1 = node1;
	while (ancestor1)
	{
		ancestor2 = node2;
		while (ancestor2)
		{
			if (ancestor1 == ancestor2)
				return (ancestor1);
			ancestor2 = ancestor2->parent;
		}
		ancestor1 = ancestor1->parent;
	}
	return (NULL);
}

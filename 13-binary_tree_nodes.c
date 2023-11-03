#include "binary_trees.h"

/**
 * binary_tree_nodes - Count nodes with at least one child in a binary tree
 * @tree: Pointer to the root node of the tree to count nodes
 * Return: Number of nodes with at least one child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t nodes = 0;

    if (tree == NULL)
        return (0);

    if (tree->left != NULL || tree->right != NULL)
        nodes = 1;

    nodes += binary_tree_nodes(tree->left);
    nodes += binary_tree_nodes(tree->right);

    return (nodes);
}

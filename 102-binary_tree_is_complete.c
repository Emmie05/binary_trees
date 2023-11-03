#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure
 *
 * Return: The height of the tree, or 0 if @tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int full_level = 0;
    int is_complete = 1;

    if (!tree)
        return (0);

    while (tree)
    {
        if (is_complete)
        {
            if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
                is_complete = 0;
        }

        if (tree->left)
        {
            if (full_level)
                is_complete = 0;
            else
                tree = tree->left;
        }
        else if (tree->right)
        {
            is_complete = 0;
            tree = tree->right;
        }
        else
        {
            full_level = 1;
            tree = tree->parent;
        }
    }

    return (is_complete);
}

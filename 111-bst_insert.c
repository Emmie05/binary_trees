#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (!tree)
        return (NULL);

    if (!*tree)
    {
        *tree = binary_tree_node(NULL, value);
        if (!*tree)
            return (NULL);
        return (*tree);
    }

    if (value < (*tree)->n)
    {
        if ((*tree)->left)
            return (bst_insert(&((*tree)->left), value));
        (*tree)->left = binary_tree_node(*tree, value);
        if (!(*tree)->left)
            return (NULL);
        return ((*tree)->left);
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right)
            return (bst_insert(&((*tree)->right), value));
        (*tree)->right = binary_tree_node(*tree, value);
        if (!(*tree)->right)
            return (NULL);
        return ((*tree)->right);
    }

    return (NULL);
}

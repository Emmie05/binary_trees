#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (size == 0 || array == NULL)
        return (NULL);

    return (create_avl_tree(array, 0, size - 1));
}

/**
 * create_avl_tree - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Index of the first element of the current subarray
 * @end: Index of the last element of the current subarray
 *
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *create_avl_tree(int *array, int start, int end)
{
    if (start > end)
        return (NULL);

    int middle = (start + end) / 2;
    avl_t *root = binary_tree_node(NULL, array[middle]);

    if (root == NULL)
        return (NULL);

    root->left = create_avl_tree(array, start, middle - 1);
    root->right = create_avl_tree(array, middle + 1, end);

    return (root);
}

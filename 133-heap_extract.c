#include "binary_trees.h"

/**
 * heapify_down - Helper function to move a node down the heap to its correct position
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t **root)
{
    heap_t *current = *root;
    int temp;

    while (1)
    {
        heap_t *left = current->left;
        heap_t *right = current->right;
        heap_t *max = current;

        if (left && left->n > max->n)
            max = left;
        if (right && right->n > max->n)
            max = right;

        if (max == current)
            break;

        temp = current->n;
        current->n = max->n;
        max->n = temp;

        current = max;
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return (0);

    int value = (*root)->n;

    if ((*root)->left)
    {
        (*root)->n = (*root)->left->n;
        free((*root)->left);
        heapify_down(root);
    }
    else
    {
        free(*root);
        *root = NULL;
    }

    return (value);
}

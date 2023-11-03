#include "binary_trees.h"

/**
 * heapify - Helper function to maintain the Max Heap property
 * @new_node: The newly inserted node
 */
void heapify(heap_t **new_node)
{
    heap_t *node = *new_node;
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        *new_node = node->parent;
    }
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    parent = *root;
    while (parent->left)
    {
        if (parent->right)
        {
            if (!parent->left->left || !parent->left->right)
                break;
            parent = parent->left;
        }
        else
            break;
    }

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->parent = parent;

    heapify(&new_node);

    return (new_node);
}

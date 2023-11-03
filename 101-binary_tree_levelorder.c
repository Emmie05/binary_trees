#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include "queue.h"  // Include the header for your queue data structure

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    queue_t *queue = NULL;

    if (!tree || !func)
        return;

    queue = queue_create();
    if (!queue)
        return;

    enqueue(queue, (void *)tree);

    while (!is_empty(queue))
    {
        binary_tree_t *current = (binary_tree_t *)dequeue(queue);

        func(current->n);

        if (current->left)
            enqueue(queue, (void *)(current->left));
        if (current->right)
            enqueue(queue, (void *)(current->right));
    }

    queue_delete(queue);
}

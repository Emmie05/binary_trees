#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array (in descending order), or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    if (!heap || !size)
        return (NULL);

    size_t i;
    int *sorted_array;
    size_t array_size = binary_tree_size(heap);

    if (array_size == 0)
    {
        *size = 0;
        return (NULL);
    }

    sorted_array = malloc(sizeof(int) * array_size);
    if (!sorted_array)
        return (NULL);

    for (i = 0; i < array_size; i++)
    {
        sorted_array[i] = heap->n;
        heap_extract(&heap);
    }

    *size = array_size;
    return (sorted_array);
}

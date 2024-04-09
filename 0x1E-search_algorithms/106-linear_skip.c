#include "search_algos.h"
#include <stdio.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express_node = NULL, *prev_node = list;

    if (list == NULL)
        return (NULL);

    express_node = list->express;

    printf("Value checked at index [%lu] = [%d]\n", express_node->index, express_node->n);
    while (express_node && express_node->n < value)
    {
        prev_node = express_node;
        express_node = express_node->express;
        if (!express_node)
            printf("Value found between indexes [%lu] and [%lu]\n",
                   prev_node->index, express_node->index);
        else
            printf("Value checked at index [%lu] = [%d]\n", express_node->index, express_node->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev_node->index, express_node->index);

    while (prev_node && prev_node->index <= express_node->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev_node->index, prev_node->n);
        if (prev_node->n == value)
            return (prev_node);
        prev_node = prev_node->next;
    }

    return (NULL);
}

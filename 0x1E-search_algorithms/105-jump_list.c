#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted list using Jump search
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t step = sqrt(size), prev = 0, i;

    if (list == NULL)
        return (NULL);

    while (list->index < size && list->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
        prev = list->index;
        for (i = 0; list->next != NULL && i < step; i++)
            list = list->next;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, list->index);

    while (prev <= list->index && list->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev, list->n);
        if (list->n == value)
            return (list);
        prev++;
        list = list->next;
    }

    return (NULL);
}

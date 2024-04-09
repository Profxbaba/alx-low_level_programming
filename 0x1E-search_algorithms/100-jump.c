#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array using jump search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;

	if (array == NULL)
		return (-1);

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += step;
		if (prev >= size)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

	while (array[prev - step] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev - step, array[prev - step]);
		prev -= 1;
		if (prev == 0)
			break;
	}

	if (array[prev - step] == value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev - step, array[prev - step]);
		return (prev - step);
	}

	return (-1);
}


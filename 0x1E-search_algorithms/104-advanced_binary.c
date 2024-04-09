#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary - Searches for a value in a sorted array using advanced
 * binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid = size / 2;
	int *sub_array;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");

	if (array[mid] == value)
	{
		if (size == 1 || array[mid - 1] < value)
			return (mid);
	}

	if (array[mid] < value)
	{
		sub_array = array + mid + 1;
		return (advanced_binary(sub_array, size - mid - 1, value) + mid + 1);
	}
	else
	{
		sub_array = array;
		return (advanced_binary(sub_array, mid, value));
	}
}

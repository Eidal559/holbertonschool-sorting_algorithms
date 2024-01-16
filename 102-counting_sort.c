#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - This function sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array containing integers to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, k;
	size_t i, j, array_size;

	if (array == NULL || size <= 1)
		return;
	array_size = array[0];
	for (i = 0; array[i]; i++)
	{
		if (array[i] > (int)array_size)
			array_size = array[i];
	}

	array_size += 1;

	count_array = malloc(array_size * sizeof(int *));
	if (count_array == NULL)
		return;

	for (i = 0; i < array_size; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]] += 1;

	for (i = 0; i <= array_size; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, array_size);

	for (i = 1, j = 0; i <= array_size; i++)
		if (count_array[i] != count_array[i - 1])
		{
			for (k = 0; k < count_array[i] - count_array[i - 1]; k++)
				array[j++] = i;
		}
	free(count_array);
}

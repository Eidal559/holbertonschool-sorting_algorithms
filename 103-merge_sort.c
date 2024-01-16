#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * merge - function to sort the subarrays
 * @low: the lower index
 * @mid: the middle index
 * @high: the higher index
 * @src: input
 * @dest: data destination
 * Return: Void
 */

void merge(size_t low, size_t mid, size_t high, int *dest, int *src)
{
	size_t x, y, z;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + low, mid - low);
	printf("[right]: ");
	print_array(src + mid, high - mid);

	x = low;
	y = mid;
	z = low;

	for (; z < high; z++)
	{
		if (x < mid && (y >= high || src[x] <= src[y]))
		{
			dest[z] = src[x];
			x++;
		}

		else
		{
			dest[z] = src[y];
			y++;
		}
	}

	printf("[Done]: ");
	print_array(dest + low, high - low);
}

/**
 * split_array - function that splits the array
 * @low: the lower index
 * @high: the higher index
 * @array: array
 * @base: copy of the array;
 * Return: void
 */

void split_array(size_t low, size_t high, int *array, int *base)
{
	size_t mid = 0;

	if (high - low < 2)
	{
		return;
	}

	mid = (low + high) / 2;

	split_array(low, mid, array, base);
	split_array(mid, high, array, base);

	merge(low, mid, high, array, base);

	memcpy(base + low, array + low, (high - low) * sizeof(int));
}

/**
 * merge_sort - function that sorts an array of integers in ascending
 * order using the merge sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: Void
 */

void merge_sort(int *array, size_t size)
{
	size_t x;
	int *base = NULL;

	if (size < 2 || array == NULL)
	{
		return;
	}

	base = malloc(sizeof(int) * size);

	if (base == NULL)
	{
		return;
	}

	for (x = 0; x < size; x++)
	{
		base[x] = array[x];
	}

	split_array(0, size, array, base);
	free(base);
}

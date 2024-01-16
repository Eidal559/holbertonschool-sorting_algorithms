#include "sort.h"

/**
 * swap_integers - This function swaps the positions of two integers
 * in an array
 * @array: The array containing the integers to be swapped
 * @int_1: Integer to be swapped
 * @int_2: Integer to be swapped
 */

void swap_integers(int *array, int int_1, int int_2)
{
	int temp;

	temp = array[int_1];
	array[int_1] = array[int_2];
	array[int_2] = temp;
}

/**
 * shell_sort - This function sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: Size of the array
 * @array: list of integers to be sorted in ascending order
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (gap < size / 3)
	{
		gap = 3 * gap + 1;
	}
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
			{
				swap_integers(array, index, index - gap);
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}

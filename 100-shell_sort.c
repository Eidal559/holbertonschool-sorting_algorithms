#include "sort.h"

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
	unsigned int gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}

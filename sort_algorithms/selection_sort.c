/*
 * sort_algorithm/selection_sort.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 *
 * Algorithm Complexity: O(n*n)
 */

#include <stdio.h>

#include "support.h"

void selection_sort(int arr[], int n)
{
	int i;
	int j;
	int min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
			// Swap the found minimum element with the first element
			if (min_idx != i)
			{
				swap(&arr[min_idx], &arr[i]);
			}
		}
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	selection_sort(arr, n);
	
	printf("Sorted array: \n");
	printf_array(arr, n);
	
	return 0;
}

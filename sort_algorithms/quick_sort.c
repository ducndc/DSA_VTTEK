/*
 * sort_algorithm/quick_sort.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 *
 * Algorithm Complexity: O(nlog(n))
 */

#include <stdio.h>

#include "support.h"

#define ENDL (printf("\n"))

int get_partition(int arr[], int low, int hight)
{
	int pivot = arr[hight];
	int i = (low - 1);

	for (int j = low; j <= (hight-1); j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i+1], &arr[hight]);

	return (i + 1);
}

void quick_sort(int arr[], int low, int hight)
{
	if (low < hight)
	{
		int piv = get_partition(arr, low, hight);

		quick_sort(arr, low, piv-1);
		quick_sort(arr, piv+1, hight);
	}
}

int main()
{
	int arr[] = {11, 33, 22, 88, 22, 99, 77, 66};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("%d ", n);

	quick_sort(arr, 0, n-1);

	print_array(arr, n);
	
	return 0;
}

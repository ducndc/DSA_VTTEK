/*
 * sort_algorithm/heap_sort.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 *
 * Algorithm Complexity: O(nlog(n))
 */

#include <stdio.h>

#include "support.h"

#define ENDL (printf("\n"))

/* To heapify a subtree rooted with node i */
void heapify(int arr[], int N, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if ((left < N) && (arr[left] > arr[largest]))
	{
		largest = left;
	}
	if ((right < N) && (arr[right] > arr[largest]))
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, N, largest);
	}
}

/* main function to do heap sort */
void heap_sort(int arr[], int N)
{
	for (int i = N/2 - 1; i >= 0; i--)
	{
		heapify(arr, N, i);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	int arr[] = {44, 11, 99, 88, 44, 77, 33};
	int N = sizeof(arr) / sizeof(arr[0]);
	
	heap_sort(arr, N);

	print_array(arr, N);

	return 0;
}

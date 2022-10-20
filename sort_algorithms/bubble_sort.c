/*
 * sort_algorithm/bubble_sort.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 *
 * Algorithm Complexity: O(n*n)
 */

#include <stdio.h>

#include "support.h"

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubble_sort(int arr[], int n)
{
    int i;
    int j;

    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
 
/* Function to print an array */
void printf_array(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);
    
    printf("Sorted array: \n");
    printf_array(arr, n);
    
    return 0;
}

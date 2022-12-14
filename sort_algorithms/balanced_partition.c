/*
 * sort_algorithm/balanced_partition.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 *
 * Algorithm Complexity: O(n*n)
 */

#include <stdio.h>

/* Swap 2 position */
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Bubble sort */
void bubble_sort(int arr[], int distance[], int n)
{
    int i;
    int j;

    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (distance[j] > distance[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
				swap(&distance[j], &distance[j + 1]);
            }
        }
    }
}

int main()
{
	int test_num;
	scanf("%d", &test_num);              	                  	

	while (test_num--)
	{
		int house_num;
		int x[house_num];
		int y[house_num];
		int person[house_num];
		int distance[house_num];
		int sum = 0;
		int tmp_sum = 0;
		int tmp_sum_1 = 0;

		scanf("%d", &house_num);

		for (int i = 0; i < house_num; i++)
		{
			scanf("%d", &x[i]);
			scanf("%d", &y[i]);
			scanf("%d", &person[i]);
		}

		for (int i = 0; i < house_num; i++)
		{
			distance[i] = x[i] - y[i];
			sum += person[i];
		}

		bubble_sort(person, distance, house_num);

		for (int i = 0; i < house_num; i++)
		{
			tmp_sum += person[i];
			if (sum % 2 != 0)
			{
				break;
			}
			if (tmp_sum == (sum / 2))
			{
				printf("YES\n");
				goto break_label;
			}
		}
		
		for (int i = 1; i < house_num; i++)
		{	
			tmp_sum = 0;
			tmp_sum_1 = 0;

			for (int j = 0; j < i; j++)
			{
				tmp_sum += person[j];
			}
			for (int j = i+1; j < house_num; j++)
			{
				tmp_sum_1 += person[j];
			}
			if (tmp_sum_1 == tmp_sum)
			{
				printf("YES\n");
				goto break_label;
			}
		}

		printf("NO\n");

		break_label: continue;
	}
}

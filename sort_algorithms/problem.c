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
		scanf("%d", &house_num);
		int x[house_num];
		int y[house_num];
		int person[house_num];
		int distance[house_num];
		float sum = 0;

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

		bubble_sort(distance, person, house_num);
		float tmp_sum = 0;
		for (int i = 0; i < house_num; i++)
		{
			tmp_sum += person[i];
			if (tmp_sum == (sum / 2))
			{
				printf("YES\n");
				goto break_label;
			}
		}
		for (int i = 1; i < house_num; i++)
		{	
			tmp_sum = 0;
			for (int j = 0; j < i; j++)
			{
				tmp_sum += person[j];
				if (tmp_sum == ((sum - person[i]) / 2))
				{
					printf("YESs\n");
					goto break_label;
				}
			}
		}
		printf("NO\n");
		break_label: continue;
	}
}

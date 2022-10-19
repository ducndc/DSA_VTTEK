#include <stdio.h>

#include "support.h"

/* swap 2 position in array */
void 
swap(value_type *a, value_type *b)
{
    value_type tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Function to print an array */
void 
print_array(value_type arr[], int size)
{
	for (int i=0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	ENDL;
}

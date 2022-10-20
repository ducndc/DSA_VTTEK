/*
 * dynamic_array/lib/vector.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang 
 *
 * Algorithm Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "../lib/vector.h"

bool suffix_array(vector a, vector b)
{
    vector_sort(a);
    vector_sort(b);

    return vector_compare(a, b);
}

bool suffix_automaton(vector a, vector b)
{
	int n = 0;

	for (int i = 0; i < vector_size(a) && n < vector_size(b); i++)
	{
		n += (vector_get(a, i) == vector_get(b, n));
	}

	return (n == vector_size(b));
}

bool suffix_both(vector a, vector b)
{
	for (int i = 0; i < vector_size(b); i++)
	{
		int tmp = vector_find(a, vector_get(b, i));

		if (tmp == -1)
		{
			return false;
		} 

		vector_add_at(a, tmp, '0');
	}

	return true;
}

int main()
{
	char str[20];
	char str1[20];

	scanf("%s", &str);
	scanf("%s", &str1);

	vector v;
	vector v1;
	vector a;
	vector b;

	v = vector_create();
	v1 = vector_create();
	a = vector_create();
	b = vector_create();

	for (int i = 0; i < strlen(str); i++)
	{
		vector_add(v, str[i]);
		vector_add(a, str[i]);
	}

	for (int i = 0; i < strlen(str1); i++)
	{
		vector_add(v1, str1[i]);
		vector_add(b, str1[i]);
	}

	if (suffix_array(a, b))
	{
		printf("array\n");
	}
	else if (suffix_automaton(v, v1))
	{
		printf("automaton\n");
	}
	else if (suffix_both(v, v1))
	{
		printf("both\n");
	}
	else
	{
		printf("need tree\n");
	}

	return 0;
}
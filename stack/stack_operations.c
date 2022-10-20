/*
 * stack/heap_sort.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 *
 * Algorithm Complexity: O(nlog(n))
 */

#include <stdio.h>

typedef unsigned long int ULLI; 

/* Find maximum value of element */
ULLI max_element (ULLI a[], ULLI n)
{
	ULLI maximum = a[0];

	for (ULLI i = 1; i < n; i++)
	{	
		if (maximum < a[i])
		{
			maximum = a[i];
		}
	}
	
	return maximum;
}

int main()
{
	ULLI n;
	ULLI k;

	scanf("%lld %lld", &n, &k);

	ULLI a[n];

	for (ULLI i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}

	if ((1 == n) && (k % 2 != 0))
	{
		printf("-1");
	}
	else if (k == n)
	{
		printf("%lld", max_element(a, n-1));
	}
	else if (k < n)
	{
		ULLI maximum = max_element(a, k-1);
		if (maximum > a[k])
		{
			printf("%lld", maximum);
		}
		else
		{
			printf("%lld", a[k]);
		}
	}
	else
	{
		printf("%lld", max_element(a, n));
	}

	return 0;
}
/*
 * string/distint_substring.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 *
 * Algorithm Complexity: O(n)
 *
 * Input 
 * The first line contains a single integer T denoting the number of test cases.
 * For each test case, the only line of input contains a single integer N.
 * Output 
 * For each test case (in a separate line), output the minimum length of a good string 
 * which has at least N distinct substrings.
 */

#include <stdio.h>

#define MIN(x, y) ({ \
	typeof(x) _x = x; \
	typeof(y) _y = y; \
	(_x < _y) ? (_x) : (_y); \
	})

#define ENDL (printf("\n"))

int main()
{
	int test_num;
	scanf("%d", &test_num);

	while (test_num--)
	{
		int N;
		scanf("%d", &N);
		
		int ans = 1e9;

		for (int i = 0; i*i <= 2*(N+1); i++)
		{
			int j = (N + 1 + i) / (i + 1) - 1;
			ans = MIN(ans, i + j);
		}

		printf("%d", ans);
		ENDL;
	}
}
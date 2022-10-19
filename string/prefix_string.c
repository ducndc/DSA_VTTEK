/**
 * Problem 
 * Two strings  and  comprising of lower case English letters are compatible 
 * if they are equal or can be made equal by 
 * following this step any number of times:
 * Select a prefix from the string  (possibly empty), 
 * and increase the alphabetical value of all the characters 
 * in the prefix by the same valid amount. For example if the string is  
 * and we select the prefix  then we can convert it to  
 * by increasing the alphabetical value by 1. 
 * But if we select the prefix  then we cannot increase the alphabetical value.
 * Your task is to determine if given strings  and  are compatible.
 * 
 * O(n)
 * */

#include <stdio.h>
#include <string.h>

int 
main()
{
	char A[1000000];
	char B[1000000];
	int C[1000000];
	scanf("%s", &A);
	scanf("%s", &B);

	if (strlen(A) != strlen(B))
	{
		printf("NO");
		return 0;
	}
	for (int i = 0; i < (strlen(B)); i++)
	{
		C[i] = (B[i] - A[i]);
	}

	for (int i = 0; i < (strlen(B)-1); i++)
	{
		if (C[i] < C[i+1] && C[i] < 0)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
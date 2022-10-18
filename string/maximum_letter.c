/**
 * Lonely Y loves his string  of lowercase letters, 
 * Y is about to escape so he should choose just one lowercase letter  
 * and carry all letters in  which is equal to  with himself.
 * What is the maximum number of letters Y can carry with himself?
 * Input
 * First line contains only , legnth of string .
 * Second line contains string  of lowercase letters.
 * 
 * O(n)
 * */

#include <stdio.h>
#include <string.h>

int main()
{
   char string[100000];
   int c = 0;
   int count[26] = {0};
   int x;
   int num;
   int max_count = -1;
   scanf("%d", &num);
   
   scanf("%s", &string);

   while (string[c] != '\0') 
   {
      if (string[c] >= 'a' && string[c] <= 'z') 
      {
         x = string[c] - 'a';
         count[x]++;
      }
      c++;
   }
   for (c = 0; c < 26; c++)
   {
   		if (max_count < count[c])
   		{
   			max_count = count[c];
   		}
   }
   printf("%d", max_count);
         
   return 0;
}
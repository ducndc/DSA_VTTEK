/*
 * stack/fun_game.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 *
 * Algorithm Complexity: O(n)
 */

#if 0
   1st step: A picks 1. B picks 3. B > A. So output is 2. A removes 1.
   2nd step: A picks 2. B picks 3. B > A. So output is 2. A removes 2.
   3rd step: A picks 3. B picks 3. B = A. So output is 0. A removes 3. 
   B removes 3.
#endif

#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

/* Implement follow rule of game */
void fun_game (int* arr , int size) 
{
   int A_picked_num;
   int B_picked_num;
   int index_A = 0;
   int index_B = (size - 1);
  
   while (index_A < size && index_B > -1)
   {
      if (arr[index_A] > arr[index_B])
      {
         printf("1 ");
         index_B -= 1;
      }
      else if (arr[index_A] < arr[index_B])
      {
         printf("2 ");
         index_A += 1;
      }
      else
      {
         printf("0 ");
         index_A += 1;
         index_B -= 1;
      }
   }
}

int main() 
{
   int n;
   int i_arr;
   int *arr = (int *)malloc(n * sizeof(int));

   scanf("%d", &n);

   for (i_arr = 0; i_arr < n; i_arr++)
   {
      scanf("%d", &arr[i_arr]);
   }

   fun_game(arr, n);

   return 0;
}
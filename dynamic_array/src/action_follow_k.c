/*
 * dynamic_array/src/action_follow_k.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang 
 *
 * 
 * 5 -> K = 5
 * 1 -> k = 1
 * 2 -> add 2
 * 1 -> k = 1
 * 4 -> add 4
 * 1 -> k = 1
 * 5 -> add 5
 * 3 -> k = 3
 * 1 -> print 1 th smallest
 * 4 -> k = 4
 * 1 -> L = 1
 * 3 -> R = 3
 * 
 * output 2 1
 * 
 * Algorithm Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "../lib/vector.h"

#define INT(x) (scanf("%d", &x))
#define PRINT(s) (printf("%d", s))

/* Get gcd of two number */
int gcd(int a, int b)
{
    if (b == 0) 
    {
        return a;
    }
    else
    {
        return (gcd(b, a % b));
    }
}

/* Get gcd of n number */
int get_gcd_in_range(vector v, int left, int right)
{
    int result = vector_get(v, 0);

    if (left < 0)
    {
        left = 0;
    }
    if (right > vector_size(v))
    {
        right = vector_size(v);
    }
    for (int i = (left-1); i < right; i++)
    {
        result = gcd(vector_get(v, i), result);
        if (result == 1)
        {
            return 1;
        }
    }

    return result;
}

/* Find x th smallest in the dynamic array */
int x_th_smallest(vector v, int x)
{
    vector_sort(v); 

    return (vector_get(v, x-1));
}

/* Solve the action follow k problem */
int main(int argc, char const *argv[])
{
    vector v;
    v = vector_create();
    int q;
    INT(q);

    while (q > 0)
    {
        --q;
        int k, x;
        INT(k);

        if (k == 1)
        {
            INT(x);
            vector_add(v, x);
        }
        else if (k == 2)
        {
            INT(x);
            if (x < 0 || x > vector_size(v))
            {
                printf("no this element");
                continue;
            }
            int index = vector_find(v, x);
            if (-1 == index)
            {
                printf("no this element");
            }   
            vector_remove_at(v, index);
        }
        else if (k == 3)
        {
            INT(x);
            int a = x_th_smallest(v, x);
            PRINT(a);
        }
        else if (k == 4)
        {
            int L, R;
            INT(L);
            INT(R);
            int a = get_gcd_in_range(v, L, R);
            PRINT(a);
        }
    }

    return 0;
}
#if 0
    Use the counting sort to order a list of strings associated with integers. 
    If two strings are associated with the same integer, 
    they must be printed in their original order, i.e. 
    your sorting algorithm should be stable. 
    There is one other twist: strings in the first half 
    of the array are to be replaced 
    with the character - (dash, ascii 45 decimal).

    Insertion Sort and the simple version of Quicksort are stable, 
    but the faster in-place version of 
    Quicksort is not since it scrambles around elements while sorting.

    Design your counting sort to be stable.
#endif

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */
void 
countSort(int arr_rows, int arr_columns, char*** arr) 
{
    int i;
    int j;
    int k;
    int *f_array;
    int *f_array_i;
    char *** result;

    result = (char***)calloc(100, sizeof(char**)); //sorted subarray storage
    f_array_i = (int*)calloc(100, sizeof(int));    //element frequency array

    /* track subarray string indexes when sorting arr into result arrays */
    f_array = (int*)calloc(100, sizeof(int));      

    /* count freuqency and substitute dashes */
    for (i = 0; i < arr_rows; i++)
    {
        if (i < (arr_rows / 2))
        {
            strcpy(arr[i][1], "-");
        }
        f_array[atoi(arr[i][0])]++;
    }

    /* use the frequency array to allocate memory for sorted subarrays */
    for (i = 0; i < 100; i++)
    {
        result[i] = (char **)calloc(f_array[i], sizeof(char*));
    }

    /* move string pointers into the sorted subarrays */
    for (i = 0; i < arr_rows; i++)
    {
        j = atoi(arr[i][0]);
        result[j][f_array_i[j]] = arr[i][1];
        f_array_i[j]++;
    }

    /* print the sorted result */
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < f_array[i]; j++)
        {
            printf("%s ", result[i][j]);
        }
        free(result[i]);  //free subarray
    }
    /* free remaining allocated memory */
    free(f_array);
    free(f_array_i);
    free(result);
}

int 
main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    char*** arr = malloc(n * sizeof(char**));

    for (int i = 0; i < n; i++) 
    {
        *(arr + i) = malloc(2 * (sizeof(char*)));
        char** arr_item_temp = split_string(rtrim(readline()));
        for (int j = 0; j < 2; j++) 
        {
            char* arr_item = *(arr_item_temp + j);
            *(*(arr + i) + j) = arr_item;
        }
    }
    countSort(n, 2, arr);
    return 0;
}

char* 
readline() 
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    while (true) 
    {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) 
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 
            || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) 
        {
            data = '\0';
            break;
        }
    }

    if (data[data_length - 1] == '\n') 
    {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
        if (!data)
        {
            data = '\0';
        }
    } 
    else 
    {
        data = realloc(data, data_length + 1);
        if (!data) 
        {
            data = '\0';
        } 
        else
        {
            data[data_length] = '\0';
        }
    }
    return data;
}

char* 
ltrim(char* str) 
{
    if (!str) 
    {
        return '\0';
    }

    if (!*str) 
    {
        return str;
    }

    while (*str != '\0' && isspace(*str)) 
    {
        str++;
    }

    return str;
}

char* rtrim(char* str) 
{
    if (!str) 
    {
        return '\0';
    }

    if (!*str) 
    {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) 
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char
**split_string(char* str) 
{
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) 
    {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) 
        {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int
parse_int(char* str) 
{
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') 
    {
        exit(EXIT_FAILURE);
    }

    return value;
}

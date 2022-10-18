/**
 * vector.c
 * 
 * author: Duc
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "vector.h"

#define INITIAL_CAPACITY 64
#define min(x, y) ((x < y) ? (x) : (y))

struct _vector {
	value_type* array;
	int size;
	int capacity;
};

/* create a vector */
vector vector_create()
{
	vector v = (vector)malloc(sizeof(struct _vector));
	if (NULL == v)
	{
		fprintf(stderr, "Not enough memory!");
		/* terminates the process by raising a SIGABRT signal */
		abort();
	}

	v->size = 0;
	v->capacity = INITIAL_CAPACITY;
	v->array = (value_type*)malloc(sizeof(value_type) * v->capacity);
	
	if (NULL == v->array)
	{
		fprintf(stderr, "Not enough memory!");
		abort();
	}

	return v;
}

/* destroy a vector */
void vector_destroy(vector v)
{
	assert(v);
	free(v->array);
	free(v);
	v->array = NULL;
	v = NULL;
}

/* vector double capacity */
static
void vector_double_capacity(vector v)
{
	assert(v);
	int new_capacity = 2 * v->capacity;
	value_type *new_array = (value_type*)malloc( \
		sizeof(value_type)*new_capacity);
	if (NULL == new_array)
	{
		fprintf(stderr, "Not enough memory!");
		abort();
	}
	for (int i = 0; i < v->size; i++)
	{
		new_array[i] = v->array[i];
	}

	free(v->array);
	v->array = new_array;
	v->capacity = new_capacity;
}

/* half capacity of vector */
static
void vector_half_capacity(vector v)
{
	assert(v);
	if (v->capacity <= INITIAL_CAPACITY)
	{
		return;
	}
	int new_capacity = v->capacity / 2;
	value_type *new_array = (value_type*)malloc(\
		sizeof(value_type) * new_capacity);
	if (NULL == new_array)
	{
		fprintf(stderr, "Not enough memory!");
		abort();
	}
	for (int i = 0; i < min(v->size, new_capacity); i++)
	{
		new_array[i] = v->array[i];
	}

	free(v->array);
	v->array = new_array;
	v->capacity = new_capacity;
	v->size = min(v->size, new_capacity);
}

/* get a vector */
value_type vector_get(vector v, int i)
{
	/* if v return 0 then call to abort() */
	assert(v);
	if (i < 0 || i >= v->size)
	{
		fprintf(stderr, "Out of index!");
		abort();
	}
	return v->array[i];
}

/* put a vector */
void vector_put(vector v, int i, value_type value)
{
	assert(v);
	if (i < 0 || i >= v->size)
	{
		fprintf(stderr, "Out of index!");
		abort();
	}
	v->array[i] = value;
}

/* put vector at the middle */
void vector_add_at(vector v, int i, value_type value)
{
	assert(v);
	if (i < 0 || i >= v->size)
	{
		fprintf(stderr, "out of index!");
		abort();
	}
	if (v->size >= v->capacity)
	{
		vector_double_capacity(v);
	}
	for (int j = v->size; j > i; j--)
	{
		v->array[j] = v->array[j-1];
	}
	v->array[i] = value;
	v->size++;
}

/* add element at the end of vector */
void vector_add(vector v, value_type value)
{
	assert(v);
	if (v->size >= v->capacity)
	{
		vector_double_capacity(v);
	}
	v->array[v->size++] = value;
}

/* remove a element */
value_type vector_remove_at(vector v, int i)
{
	assert(v);
	if (i < 0 || i >= v->size)
	{
		fprintf(stderr, "Out of index!");
		abort();
	}

	value_type ret = v->array[i];
	for (int j = j+1; j < v->size; j++) 
	{
		v->array[j-1];
	}
}

/* Is vector empty */
int vector_is_empty(vector v)
{
	assert(v);
	return (v->size == 0);
}

/* Get size of a vector */
int vector_size(vector v)
{
	assert(v);
	return (v->size);
}

/* Clear a vector */
void vector_clear(vector v)
{
	assert(v);
	v->size = 0;
	while (v->capacity > INITIAL_CAPACITY)
	{
		vector_half_capacity(v);
	}
}

/* sort a vector */
void vector_sort(vector v)
{
	assert(v);
	for (int i = 0; i < v->size; i++)
	{
		for (int j = 0; j < v->size; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (v->array[i] < v->array[j])
			{
				value_type tmp = v->array[i];
				v->array[i] = v->array[j];
				v->array[j] = tmp;
			}
		}
	}
}

/* compare between 2 vectors */
int vector_compare(vector a, vector b)
{
	assert(a);
	assert(b);
	for (int i = 0; i < a->size; i++)
	{
		if (a->array[i] != b->array[i])
		{
			return 0;
		}
	}	
	return 1;
}

/* find index of element */
int vector_find(vector a, value_type value)
{
	for (int i = 0; i < a->size; i++)
	{
		if (value == a->array[i])
		{
			return i;
		}
	}
	return -1;
}

/*
 * dynamic_array/lib/vector.h
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang 
 */

#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct _vector* vector;
typedef int value_type;

/* Public API in vector */
vector vector_create();
void vector_destroy(vector);

value_type vector_get(vector, int);
void vector_put(vector, int, value_type);

void vector_add(vector, value_type);

void vector_add_at(vector, int, value_type);
value_type vector_remove_at(vector, int);

int vector_is_empty(vector);
int vector_size(vector);
void vector_clear(vector);

void vector_sort(vector);
int vector_compare(vector, vector);

int vector_find(vector, value_type);

#endif
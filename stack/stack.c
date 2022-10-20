/*
 * stack/heap_sort.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 */

#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack *stack_t;
typedef int value_type;

/* Public function in stack */
void stack_create(stack_t p_stack);
bool stack_is_empty();
int stack_push(stack_t p_stack, value_type value);
int stack_size();
value_type stack_pop(stack_t p_stack);

#endif 
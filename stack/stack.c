/**
 * stack.h
 * 
 * author: Chung Duc Nguyen Dang
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

struct stack {
     value_type data;
     stack_t *next;
};

/* Create a stack */
void stack_create(stack_t p_stack)
{
  	*p_stack = NULL;
}

/* Push to the stack */
int stack_push(stack_t p_stack, value_type data)
{
	  stack_t new_node;
	  new_node = malloc(sizeof(stack_t));
	  /* can not create space */
	  if (NULL == new_node)
	  {
	    	return -1;
	  }
	  new_node->value = data;
	  /* stack is empty */
	  if (NULL == *p_stack)
	  {
	    	new_node->next = NULL;
	  }
	  else
	  {
	    	new_node->next = p_stack;
	  }
	  *p_stack = new_node;
	  return 1;
}

/* Pop from the stack */
value_type stack_pop(stack_t p_stack)
{
	  stack_t delete_node;
	  /* stack is empty */
	  if (NULL == p_stack)
	  {
	    	return -1;
	  }
	  delete_node = p_stack;
	  if (NULL == delete_node->next)
	  {
	    	stack_create(p_stack);
	  }
	  else
	  {
	    	p_stack = delete_node->next;
	  }
	  free(delete_node);
}

/* Check the stack is empty */
bool stack_is_empty(stack_t p_stack)
{
	  if (NULL == p_stack)
	  {
	    	return true;
	  }
	  return false;
}

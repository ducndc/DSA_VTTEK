#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int 
main()
{
	node_t *list = malloc(sizeof(node_t));
	list->next = NULL;
	list_add(&list, 1);
	list_add(&list, 2);
	list_traverse(list);
	return 0;
}
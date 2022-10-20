/*
 * queue/lib/list.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/* enqueue a element */
void enqueue(queue_t *queue, value_type data)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));

	new_node->data = data;
	new_node->next = NULL;

	queue->tail->next = new_node;
	queue->tail = new_node;
	queue->size++;
}

/* dequeue a element */
value_type dequeue(queue_t *queue)
{
	if (queue->size == 0)
	{
		printf("The queue is empty!");
		return NULL;
	}

	value_type data;

	node_t *tmp = NULL;

	tmp = queue->head;
	queue->head = queue->head->next;
	queue->size--;

	return data;
}

/* create a queue */
queue_t *create_queue()
{
	queue_t queue;

	queue.size = 0;
	queue.head = NULL;
	queue.tail = NULL;
	queue.enqueue = &enqueue;
	queue.dequeue = &dequeue;

	return queue;
}
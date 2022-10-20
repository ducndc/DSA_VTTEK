/*
 * queue/lib/list.h
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 */

#ifndef __QUEUE__H__
#define __QUEUE__H__

typedef struct queue queue_t;
typedef struct node node_t;
typedef int value_type;

struct node {
    value_type data;
    node_t *next;
};

struct queue {
    int size;
    node_t *head;
    node_t *tail;

    void (*enqueue)(queue_t *, value_type);
    value_type (*dequeue)(queue_t *);
    node_t *(*create_node)(value_type);   
};

/* Public function in queue */
void enqueue(queue_t *queue, value_type data);
value_type dequeue(queue_t *queue);
queue_t *create_queue();
node_t *create_node(value_type data);

#endif

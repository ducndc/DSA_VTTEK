/*
 * linked_list/lib/list.h
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 */

#ifndef __LIST_H__
#define __LIST_H__

typedef struct node node_t;
typedef struct linked_list list_t;
typedef int value_type;

struct node {
    value_type data;
    node_t *prev;
    node_t *next;
};

struct linked_list {
    node_t *head;
    node_t *tail;
    int size;

    void (*add)(list_t *, value_type, int);
    void (*add_last)(list_t *, value_type);
    void (*add_first)(list_t *, value_type);
    void (*insert_before)(list_t *, node_t *, node_t *);
    value_type (*get)(list_t *, int);
    value_type (*get_last)(list_t *);
    value_type (*get_first)(list_t *);
    value_type (*remove)(list_t *, int);
    value_type (*remove_last)(list_t *);
    value_type (*remove_first)(list_t *);

    node_t *(*create_node)(value_type);
};

/* Public function in linked list */
void add(list_t *list, value_type value, int position);
void add_last(list_t *list, value_type value);
void add_first(list_t *list, value_type value);
void insert_before(list_t *list, node_t *node, node_t *new_node);
value_type get(list_t *list, int position);
value_type get_first(list_t *list);
value_type get_last(list_t *list);
value_type list_remove(list_t *list, int position);
value_type remove_first(list_t *list);
value_type remove_last(list_t *list);
list_t create_linked_list();
node_t *create_node(value_type value);

#endif

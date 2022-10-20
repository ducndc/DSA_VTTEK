/*
 * linked_list/lib/list.c
 *
 * Copyright (C) 2022 Chung Duc Nguyen Dang
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

typedef struct node node_t;
typedef struct linked_list list_t;
typedef int value_type;

/* Add a node to the list */
void add(list_t *list, value_type data, int position)
{
    if (position > list->size)
    {
        printf("Out of index!");
        return;
    }

    if (0 == position)
    {
        list->add_first(list, data);
    }
    else if (list->size == position)
    {
        list->add_last(list, data);
    }
    else
    {
        node_t *node = list->head;
        int i = 0;

        while (i < position)
        {
            node = node->next;
            i++;
        }
        node_t *new_node = list->create_node(data);

        list->insert_before(list, node, new_node);
        list->size++;
    }
}

/* Add a node to the first of list */
void add_first(list_t *list, value_type data)
{
    node_t *new_node = list->create_node(data);
    node_t *head = list->head;

    if (head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        node_t *last = list->tail;
        if (NULL == last)
        {
            last = head;
        }
        new_node->next = head;
        head->prev = new_node;
        list->head = new_node;
        list->tail = last;
    }

    list->size++;
}

/* Add a node to the last of list */
void add_last(list_t *list, value_type data)
{
    node_t *new_node = list->create_node(data);
    node_t *head = list->head;
    node_t *tail = list->tail;

    if (head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        node_t *last_node = tail;
        if (NULL == tail)
        {
            last_node = head;
        }
        last_node->next = new_node;
        new_node->prev = last_node;
        list->tail = new_node;
    }
    list->size++;
}

/* Insert a node to the first of list */
void insert_before(list_t *list, node_t *node, node_t *new_node)
{
    node_t *prev = node->prev;

    node->prev = new_node;
    new_node->next = node;
    prev->next = new_node;
    new_node->prev = prev;
}

/* Get data of a node of the list */
value_type get(list_t *list, int position)
{
    if (0 == list->size)
    {
        printf("The list is empty!");
        return -1;
    }
    else if (position >= list->size)
    {
        printf("Out of index!");
        return -1;
    }

    if (0 == position)
    {
        return (list->get_first(list));
    }
    else if (position+1 == list->size)
    {
        return (list->get_last(list));
    }
    else
    {
        node_t *node = list->head;
        int i = 0;
        while (i < position)
        {
            node = node->next;
            i++;
        }
        return node->data;
    }
}

/* Get data of a node of the first of list*/
value_type get_first(list_t *list)
{
    if (0 == list->size)
    {
        printf("The list is empty!");
        return -1;
    }

    return (list->head->data);
}

/* Get data of a node of the last of list*/
value_type get_last(list_t *list)
{
    if (0 == list->size)
    {
        printf("The list is empty!");
        return -1;
    }

    if (1 == list->size)
    {
        return get_first(list);
    }

    return list->tail->data;
}

/* Remove a node of the list */
int list_remove(list_t *list, int position)
{
    if (0 == list->size)
    {
        printf("The list is empty!");
        return -1;
    }
    else if (position >= list->size)
    {
        printf("Out of index!");
        return -1;
    }

    if (0 == position)
    {
        return list->remove_first(list);
    }
    else if (position+1 == list->size)
    {
        return list->remove_last(list);
    }
    else 
    {
        node_t *node = list->head;
        node_t *prev;
        node_t *next;
        int i = 0;
        value_type data;

        while (i < position)
        {
            node = node->next;
            i++;
        }

        data = node->data;
        prev = node->prev;
        next = node->next;
        prev->next = next;
        next->prev = prev;

        free(node);
        list->size--;

        return node->data;
    }
}

/* Remove a node of the first of list */
value_type remove_first(list_t *list)
{
    node_t *head = list->head;
    node_t *next;
    value_type data;

    if (NULL == head)
    {
        printf("The list is empty!");

        return -1;
    }

    data = head->data;
    next = head->next;
    list->head = next;

    if (next != NULL)
    {
        next->prev = NULL;
    }

    free(head);
    list->size--;

    if (list->size <= 1)
    {
        list->tail = NULL;
    }

    return data;
}

/* Remove a node of the last of list */
value_type remove_last(list_t *list)
{
    if (0 == list->size)
    {
        printf("The list is empty");

        return -1;
    }
    else
    {
        node_t *tail = list->tail;
        node_t *prev = tail->prev;
        value_type data = tail->data;
        prev->next = NULL;

        if (list->size > 1)
        {
            list->tail = prev;
        }

        list->size--;

        if (list->size <= 1)
        {
            list->tail = NULL;
        }

        return data;
    }
}

/* Create the linked list */
list_t create_linked_list()
{
    list_t list;
    list.head = NULL;
    list.tail = NULL;
    list.add = &add;
    list.add_first = &add_first;
    list.insert_before = &insert_before;
    list.get = &get;
    list.get_first = &get_first;
    list.get_last = &get_last;
    list.list_remove = &list_remove;
    list.remove_last = &remove_last;
    list.remove_first = &remove_first;
    list.create_node = &create_node;

    return list;
}

/* Create a node */
node_t *create_node(value_type data)
{
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    
    return node;
}

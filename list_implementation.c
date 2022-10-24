// Copyright 2022 Nioata Alexandra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "utils.h"
#include "macros.h"
#include "check_read.h"
#include "free_print.h"

// creates a list
linked_list_t*
create_list()
{
    linked_list_t *list;
    list = malloc(sizeof(struct linked_list_t));
    DIE(NULL == list, "malloc failed");
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// creates a node
node*
create_node(unsigned int data_size, const void *new_data) {
    node *new_node;
    new_node = malloc(sizeof(node));
    DIE(NULL == new_node, "malloc failed");

    new_node->data = malloc(data_size);
    if (NULL == new_node->data) {
		free(new_node);
		DIE(NULL == NULL, "malloc failed");
	}
    memcpy(new_node->data, new_data, data_size);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// add a node at the end of a list
void
add_to_a_list(linked_list_t *list, void *data, unsigned int data_size) {
    node *new_node = create_node(data_size, data);
    list->size++;
    if (list->head == NULL) {
        new_node->prev = NULL;
        list->head = new_node;
		list->tail = new_node;
        return;
    }
	list->tail->next = new_node;
	new_node->prev = list->tail;
    new_node->next = NULL;
	list->tail = new_node;
}

// goes through the list to find the node with a given index
node*
get_to_a_node(linked_list_t *list, unsigned int index)
{
    node *new_node;
    if (!list) {
        return NULL;
    } else if (!(list->size)) {
        return NULL;
    } else if (2*index < (unsigned)(1 + list->size)) {
		new_node = list->head;
		unsigned int i = 0;
		while (i < index) {
			new_node = new_node->next;
			i++;
		}
	} else {
		new_node = list->tail;
		unsigned int i = list->size - 1;
		while (i > index) {
			new_node = new_node->prev;
			i--;
		}
	}
    return new_node;
}

// delete node from a given position
void
delete_node(linked_list_t *list, int number, void (*free_data)(void*))
{
    node *temp;
    if (number == 0) {
        temp = list->head;
        list->head = list->head->next;
        if (list->head != NULL)
            list->head->prev = NULL;
    } else if (number == list->size - 1) {
        node *current = list->tail;
		temp = current;
        current = current->prev;
        if (current != NULL)
            current->next = NULL;
		list->tail = current;
    } else {
        temp = get_to_a_node(list, number);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
    }
	list->size--;
	if (list->size == 0) {
		list->head = NULL;
		list -> tail = NULL;
	}
    free_data(temp->data);
    free(temp);
}

// finds the node (at the n positon) where the list will be split
// create a list with the nodes from n+1
linked_list_t*
split_list(linked_list_t *list, int n)
{
	linked_list_t *list1;
    node *current = list->head;
    for (int i = 0; i < n; i++) {
        current = current->next;
    }
	list1 = create_list();
	list1->tail = list->tail;
	list->tail = current->prev;
	list1->head = current;
	list1->head->prev = NULL;
	list->tail->next = NULL;
	list1->size = list->size - n;
	list->size = n;
	return list1;
}

// merge two lists in one
linked_list_t*
merge_lists(linked_list_t *list1, linked_list_t *list2)
{
    linked_list_t *list = create_list();
    node *node1 = list1->head;
    node *node2 = list2->head;
    int minimum;
    if (list1->size > list2->size)
        minimum = list2->size;
    else
        minimum = list1->size;
    for (int i = 0; i < minimum; i++) {
        add_to_a_list(list, node1->data, sizeof(struct cards_t));
        add_to_a_list(list, node2->data, sizeof(struct cards_t));
        node1 = node1->next;
        node2 = node2->next;
    }
    while (node1 != NULL) {
        add_to_a_list(list, node1->data, sizeof(struct cards_t));
        node1 = node1->next;
    }
    while (node2 != NULL) {
        add_to_a_list(list, node2->data, sizeof(struct cards_t));
        node2 = node2->next;
    }
    return list;
}

// reverse a list
void
reverse_list(linked_list_t *list)
{
    node *temp, *current;
	current = list->head;
	list->head = list->tail;
	list->tail = current;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
	}
	list->head->prev = NULL;
	list->tail->next = NULL;
}

// shuffles the list
// reverse the first part of the list with index nodes
// with the part with the remaining nodes
void
shuffle_list(linked_list_t *list, int index) {
	node *node_i;
    node_i = get_to_a_node(list, index);
	list->tail->next = list->head;
	list->head->prev = list->tail;
	list->tail = node_i->prev;
	list->tail->next = NULL;
	list->head = node_i;
    list->head->prev = NULL;
}


// sort the list in ascendig order or after the priority of the cards
void
sort_list(linked_list_t *list, int dim, int (*comp)(const void*, const void*)){
	int test;
	node *current, *fin, *temp_fin;
	if (list->head == NULL)
		return;
	void *temp_data = malloc(dim);
	fin = NULL;
	do {
		test = 1;
		current = list->head;
		while (current->next != fin) {
			if (comp(current->data, current->next->data) > 0) {
				memcpy(temp_data, current->data, dim);
				memcpy(current->data, current->next->data, dim);
				memcpy(current->next->data, temp_data, dim);
				test = 0;
				temp_fin = current->next;
			}
			current = current->next;
		}
		fin = temp_fin;
	} while (test == 0);
	free(temp_data);
}

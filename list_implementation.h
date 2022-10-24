// Copyright 2022 Nioata Alexandra

#ifndef LIST_IMPLEMENTATION_H_
#define LIST_IMPLEMENTATION_H_
#include "macros.h"

linked_list_t*
create_list();

node*
create_node(unsigned int, const void *);

void
add_to_a_list(linked_list_t *, void *, unsigned int);

node*
get_to_a_node(linked_list_t *, unsigned int);

void
reverse_list(linked_list_t *);

void
delete_node(linked_list_t *, int , void (* )(void*));

linked_list_t*
split_list(linked_list_t *, int);

linked_list_t*
merge_lists(linked_list_t *, linked_list_t *);

void
sort_list(linked_list_t *, int , int (* )(const void*, const void*));

void
shuffle_list(linked_list_t *, int);
#endif  // LIST_IMPLEMENTATION_H_

// Copyright 2022 Nioata Alexandra

#ifndef FREE_PRINT_H_
#define FREE_PRINT_H_
#include "macros.h"

void
free_list(void *);

void
free_list_t(linked_list_t **, void (*)(void*));

void
print_card(void*, int);

void
print_deck(void*, int);

void
show_list(void *list, void (*)(void*, int));
#endif  // FREE_PRINT_H_

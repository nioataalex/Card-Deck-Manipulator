// Copyright 2022 Nioata Alexandra

#ifndef CHECK_READ_H_
#define CHECK_READ_H_
#include "macros.h"

int
invalid_card(int, char[]);

int
out_of_bounds(linked_list_t *, int);

int
comp_card(const void *, const void *);

int
priority(const cards_t*);

char*
read_input(void);

#endif  // CHECK_READ_H_

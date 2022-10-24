// Copyright 2022 Nioata Alexandra

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "macros.h"

void
add_deck(linked_list_t *, int);

void
del_deck_card(linked_list_t *, int, int);

void
add_cards(linked_list_t *, int, int);

void
deck_len(linked_list_t *, int);

void
shuffle_deck(linked_list_t *, int);

void
merge_decks(linked_list_t *, int, int);

void
split_deck(linked_list_t *, int, int);

void
reverse_deck(linked_list_t *, int);

void
sort_deck(linked_list_t *, int);
#endif  //  FUNCTIONS_H_

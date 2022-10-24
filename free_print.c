// Copyright 2022 Nioata Alexandra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "utils.h"
#include "macros.h"
#include "check_read.h"

// frees a deck
void
free_list(void *L)
{
    node *h = NULL, *current = NULL;
    if (L != NULL) {
        h = ((linked_list_t*) L) -> head;
    }
    while (h != NULL) {
        current = h;
        h = h -> next;
		free(current -> data);
        free(current);
    }
	free(L);
}

// frees the lists of decks
void
free_list_t(linked_list_t **L, void (*free_data)(void*))
{
    node *h = NULL, *current = NULL;
    if ((*L) != NULL)
        h = (*L) -> head;
    while (h != NULL) {
        current = h;
        h = h -> next;
        free_data(current -> data);
        free(current);
    }
    free(*L);
}

// prints the elements of a deck or a list of decks
void
show_list(linked_list_t *list, void (*print_data)(void*, int))
{
	node *current = list->head;
	int i = 0;
	while (current != NULL) {
		print_data(current->data, i);
		current = current->next;
		i++;
	}
}

// prints a card
void
print_card(void* card_info, int i)
{
    // this is useless but it was the only way to escape from a warning
    // i didn't want to change the whole approach
    i++;
	printf("\t%d ", ((cards_t *)card_info)->value);
    printf("%s\n", ((cards_t *)card_info)->symbol);
}

// prints a deck
void
print_deck(void* deck, int i)
{
	printf("Deck %d:\n", i);
	show_list((linked_list_t*)deck, print_card);
}

// Copyright 2022 Nioata Alexandra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "utils.h"
#include "macros.h"
#include "check_read.h"
#include "list_implementation.h"
#include "free_print.h"

// add a deck with a given number of cards
// creates a list and adds the cards
void
add_deck(linked_list_t *list, int index)
{
    struct cards_t card;
    int number = index;
    linked_list_t *deck = create_list();
    while (index) {
        char *line = read_input();
        char *part = strtok(line, " ");
        card.value = atoi(part);
        part = strtok(NULL, line);
        strcpy(card.symbol, part);
        if (invalid_card(card.value, card.symbol) == 0) {
            printf(INVALID_CARD);
        } else {
            add_to_a_list(deck, &card, sizeof(card));
			index--;
        }
		free(line);
    }
    add_to_a_list(list, deck, sizeof(linked_list_t));
	free(deck);
    printf("The deck was successfully created with %d cards.\n", number);
}

// deletes a card with the given index from a deck with the given index
// if a deck is empty after, the the deck will be deleted
// from the lists of decks
void
del_deck_card(linked_list_t *list, int index_deck, int index_card)
{
    node *current = get_to_a_node(list, index_deck);
    linked_list_t *deck = (linked_list_t *)current->data;
    if (out_of_bounds(deck, index_card) == 0)
    {
        printf((CARD_INDEX_OUT_OF_BOUNDS));
        printf("%d.\n", index_deck);
    } else {
        delete_node(deck, index_card, free);
		if (deck->size == 0) {
			delete_node(list, index_deck, free_list);
		}
        printf("The card was successfully deleted from deck %d.\n", index_deck);
    }
}

// finds the deck with the given index
// prints the size of it
void
deck_len(linked_list_t *list, int index)
{
    node *current = get_to_a_node(list, index);
    linked_list_t *deck = (linked_list_t *)current->data;
    printf("The length of deck %d is %d.\n", index, deck->size);
}

// finds the deck with the given index
// and shuffles it
// the first half will be reversed with the second half
void
shuffle_deck(linked_list_t *list, int index)
{
    node *current = get_to_a_node(list, index);
    linked_list_t *deck = (linked_list_t *)current->data;
    shuffle_list(deck, (deck -> size)/2);
    printf("The deck %d was successfully shuffled.\n", index);
}

// finds the two deck with the given indexes
// creates the merged list / deck
// deletes the two lists
// adds the new deck on the last position
void
merge_decks(linked_list_t *list, int index1, int index2)
{
    node *current = get_to_a_node(list, index1);
    linked_list_t *deck1 = (linked_list_t *)current->data;
    current = get_to_a_node(list, index2);
    linked_list_t *deck2 = (linked_list_t *)current->data;
    linked_list_t *new_deck = merge_lists(deck1, deck2);
    add_to_a_list(list, new_deck, sizeof(linked_list_t));
    int aux;
	int n1 = index1, n2 = index2;
    if (index1 < index2){
        aux = index1;
        index1 = index2;
        index2 = aux;
    }
    delete_node(list, index1, free_list);
    delete_node(list, index2, free_list);
	free(new_deck);
    printf("The deck %d and the deck %d were successfully merged.\n", n1, n2);
}

// the given deck is splited in 2 deck
// the first list remains on the same position
// puts the created list on the index_deck + 1 position
void
split_deck(linked_list_t *list, int index_deck, int index_split)
{
	node *current = get_to_a_node(list, index_deck);
    linked_list_t *deck = (linked_list_t *)current->data;
	if (out_of_bounds(deck, index_split) == 0) {
        printf((CARD_INDEX_OUT_OF_BOUNDS));
        printf("%d.\n", index_deck);
		return;
	} else if ((index_split > 0) && (index_split < deck->size)) {
		linked_list_t *deck1 = split_list(deck, index_split);
		node *new_node = create_node(sizeof(linked_list_t), deck1);
		new_node->next = current->next;
		current->next = new_node;
		new_node->prev = current;
		if (new_node->next != NULL)
			new_node->next->prev = new_node;
		if (index_deck == list->size - 1)
			list->tail = new_node;
		free(deck1);
		list->size++;
	}
	printf("The deck %d was successfully ", index_deck);
    printf("split by index %d.\n", index_split);
}

// add cards at the deck with the given index
// checks if the card is valid
void
add_cards(linked_list_t *list, int index_deck, int index)
{
    node *current = get_to_a_node(list, index_deck);
    linked_list_t *deck = (linked_list_t *)current->data;
    cards_t card;
    while (index) {
        char *line = read_input();
        char *part = strtok(line, " ");
        card.value = atoi(part);
        part = strtok(NULL, line);
        strcpy(card.symbol, part);
        if (invalid_card(card.value, card.symbol) == 0) {
            printf(INVALID_CARD);
        } else {
            add_to_a_list(deck, &card, sizeof(card));
			index--;
        }
		free(line);
    }
    printf("The cards were successfully added to deck %d.\n", index_deck);
}

// finds the deck with the given index and reverse it
void
reverse_deck(linked_list_t *list, int index)
{
    node *current = get_to_a_node(list, index);
    linked_list_t *deck = (linked_list_t *)current->data;
    reverse_list(deck);
    printf("The deck %d was successfully reversed.\n", index);
}

// find the deck with the given index
// sorts the list
void
sort_deck(linked_list_t *list, int index)
{
    node *current = get_to_a_node(list, index);
    linked_list_t *deck = (linked_list_t *)current->data;
    sort_list(deck, sizeof(cards_t), comp_card);
    printf("The deck %d was successfully sorted.\n", index);
}

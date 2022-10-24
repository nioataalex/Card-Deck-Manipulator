// Copyright 2022 Nioata Alexandra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "macros.h"
#include "check_read.h"
#include "list_implementation.h"
#include "free_print.h"

int main()
{
    linked_list_t *list;
    list = create_list(sizeof(struct linked_list_t));
    char *command;
    int index, index_card, index_deck, index1, index2, index_split;
    while (1) {
        command = read_input();
        char *part = strtok(command, " ");
        if (strcmp(command, "ADD_DECK") == 0) {
            part = strtok(NULL, " ");
            index = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (index == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                add_deck(list, index);
        } else if (strcmp(command, "DEL_DECK") == 0) {
            part = strtok(NULL, " ");
            index = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL) {
                printf(INVALID_COMMAND);
            } else if (out_of_bounds(list, index) == 0) {
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            } else {
                delete_node(list, index, free_list);
                printf("The deck %d was successfully deleted.\n", index);
            }
        } else if (strcmp(command, "DEL_CARD") == 0) {
            part = strtok(NULL, " ");
            index_deck = atoi(part);
            part = strtok(NULL, " ");
            if (part == NULL) {
                printf(INVALID_COMMAND);
            } else {
            index_card = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (out_of_bounds(list, index_deck) == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                del_deck_card(list, index_deck, index_card);
            }
        } else if (strcmp(command, "ADD_CARDS") == 0) {
            part = strtok(NULL, " ");
            index_deck = atoi(part);
            part = strtok(NULL, " ");
            if (part == NULL) {
                printf(INVALID_COMMAND);
            } else {
            index = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (out_of_bounds(list, index_deck) == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                add_cards(list, index_deck, index);
            }
        } else if (strcmp(command, "DECK_NUMBER") == 0) {
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else
                printf("The number of decks is %d.\n", list->size);
        } else if (strcmp(command, "DECK_LEN") == 0) {
            part = strtok(NULL, " ");
            index = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (out_of_bounds(list, index) == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                deck_len(list, index);
        } else if (strcmp(command, "SHUFFLE_DECK") == 0) {
            part = strtok(NULL, " ");
            index = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (out_of_bounds(list, index) == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                shuffle_deck(list, index);
        } else if (strcmp(command, "MERGE_DECKS") == 0) {
            part = strtok(NULL, " ");
            index1 = atoi(part);
            part = strtok(NULL, " ");
            if (part == NULL){
                printf(INVALID_COMMAND);
            } else {
            index2 = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (out_of_bounds(list, index1) == 0
                        || out_of_bounds(list, index2) == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                merge_decks(list, index1, index2);
            }
        } else if (strcmp(command, "SPLIT_DECK") == 0) {
            part = strtok(NULL, " ");
            index_deck = atoi(part);
            part = strtok(NULL, " ");
            if (part == NULL) {
                printf(INVALID_COMMAND);
            } else {
            index_split = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (out_of_bounds(list, index_deck) == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                split_deck(list, index_deck, index_split);
            }
        } else if (strcmp(command, "REVERSE_DECK") == 0) {
            part = strtok(NULL, " ");
            index = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (out_of_bounds(list, index) == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                reverse_deck(list, index);
        } else if (strcmp(command, "SHOW_DECK") == 0) {
            part = strtok(NULL, " ");
            index = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL) {
                printf(INVALID_COMMAND);
            } else if (out_of_bounds(list, index) == 0) {
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            } else {
				printf("Deck %d:\n", index);
				show_list(get_to_a_node(list, index) -> data, print_card);
			}
        } else if (strcmp(command, "SHOW_ALL") == 0) {
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else
                show_list(list, print_deck);
        } else if (strcmp(command, "SORT_DECK") == 0) {
            part = strtok(NULL, " ");
            index = atoi(part);
            part = strtok(NULL, " ");
            if (part != NULL)
                printf(INVALID_COMMAND);
            else if (out_of_bounds(list, index) == 0)
                printf(DECK_INDEX_OUT_OF_BOUNDS);
            else
                sort_deck(list, index);
        } else if (strcmp(command, "EXIT") == 0) {
            free_list_t(&list, free_list);
            free(command);
            break;
        }
        else
            printf(INVALID_COMMAND);
        free(command);
    }
    return 0;
}

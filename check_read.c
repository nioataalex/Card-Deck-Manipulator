// Copyright 2022 Nioata Alexandra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "check_read.h"

// checks if a card is valid or not
int
invalid_card(int value, char symbol[])
{
    if (value <= 0 || value >= 15)
        return 0;
    char *symbols[SYMBOL_NUMBER] = {"HEART", "DIAMOND", "CLUB", "SPADE"};
    int k = 0;
    for (int i = 0; i < SYMBOL_NUMBER; i++)
        if (strcmp(symbol, symbols[i]) == 0)
            k++;
    if (k == 1)
        return 1;
    else
        return 0;
}

// checks if the given index is bigger than the size of the given list
// or if it is negative
int
out_of_bounds(linked_list_t *list, int index)
{
    if ((list->size - 1) < index)
        return 0;
    if (index < 0)
        return 0;
    return 1;
}

// compares the value of two cards
// compares the simbols of the cards
int
comp_card(const void * c1, const void * c2)
{
	if (((cards_t* )c1)->value == ((cards_t* )c2)->value)
		return priority((cards_t* )c1 )- priority((cards_t* )c2);
	else
		return ((cards_t* )c1)->value - ((cards_t* )c2)->value;
}

// show the priority of the cards
int
priority(const cards_t* c)
{
	char *symbols[SYMBOL_NUMBER] = {"HEART", "SPADE", "DIAMOND", "CLUB"};
    for (int i = 0; i < SYMBOL_NUMBER; i++) {
        if (strcmp(c->symbol, symbols[i]) == 0)
			return i;
    }
	return SYMBOL_NUMBER + 1;
}

// read a line
char*
read_input(void)
{
	char *command;
	command = malloc(COMMAND_SIZE);
	fgets(command, COMMAND_SIZE, stdin);
	if (command[strlen(command) - 1] == '\n')
		command[strlen(command) - 1] = '\0';
	return command;
}

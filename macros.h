// Copyright 2022 Nioata Alexandra

#ifndef MACROS_H_
#define MACROS_H_
#define SYMBOL_SIZE 10
#define SYMBOL_NUMBER 4
#define COMMAND_SIZE 60
#define INVALID_CARD "The provided card is not a valid one.\n"
#define INVALID_COMMAND "Invalid command. Please try again.\n"
#define DECK_INDEX_OUT_OF_BOUNDS \
"The provided index is out of bounds for the deck list.\n"
#define CARD_INDEX_OUT_OF_BOUNDS \
"The provided index is out of bounds for deck "

typedef struct node
{
    void *data;
    struct node *next, *prev;
}node;

typedef struct cards_t
{
    int value;
    char symbol[SYMBOL_SIZE];
}cards_t;

typedef struct linked_list_t
{
    node *head, *tail;
    int size;
}linked_list_t;
#endif  //  MACROS_H_

#pragma once

#include "node.h"

struct _list
{
    node *head;
    node *tail;
};

typedef struct _list list;

list *list_create();
void list_init(list *l);
void list_insert_front(list *l, node *n);
void list_insert_back(list *l, node *n);
void list_free(list *l);
void list_print(list *l, void (*fptr)(node *n));

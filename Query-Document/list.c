#include "list.h"
#include <stdlib.h>
#include <assert.h>

list *list_create()
{
    list *l = (list *)malloc(sizeof(list));

    if(!l)
    {
        return NULL;
    }

    list_init(l);

    return l;
}

void list_init(list *l)
{
    l->head = node_create();
    l->tail = node_create();

    l->head->next = l->tail;
    l->tail->prev = l->head;
}

void list_insert_front(list *l, node *n)
{
    if(!n)
    {
        return;
    }

    n->next = l->head->next;
    n->prev = l->head;

    n->next->prev = n;
    l->head->next = n;
}

void list_insert_back(list *l, node *n)
{
    if(!n)
    {
        return;
    }

    n->next = l->tail;
    n->prev = l->tail->prev;

    n->prev->next = n;
    l->tail->prev = n;
}

void list_free(list *l)
{
    node *itr = l->head;

    while (itr)
    {
        node *tmp = itr->next;
        free(itr->data);
        free(itr);
        itr = tmp;
    }

    free(l);
}

void list_print(list *l, void (*fptr)(node *n))
{
    node *itr = l->head->next;

    while (itr != l->tail)
    {
        fptr(itr);
        itr = itr->next;
    }
}

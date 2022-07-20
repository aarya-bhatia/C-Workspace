#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

node *node_create()
{
    node *n = (node *)malloc(sizeof(node));

    n->data = NULL;
    n->next = NULL;
    n->prev = NULL;

    return n;
}

node *string_node_create(const char *s, int len)
{
    node *n = node_create();

    char *copy = malloc(len + 1);
    memcpy(copy, s, len);
    copy[len] = 0;
    n->data = copy;

    return n;
}

void node_free(node *n)
{
    free(n->data);
    free(n);
}

void string_node_print(node *n)
{
    printf("%s\n", (char *)n->data);
}

#pragma once

struct _node
{
    void *data;
    struct _node *next;
    struct _node *prev;
};

typedef struct _node node;

node *node_create();
void node_print(node *);
void node_free(node *);

node *string_node_create(const char *s, int len);
void string_node_print(node *n);

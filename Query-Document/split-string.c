#include "split-string.h"
#include <stdlib.h>
#include <string.h>

list *split_string(const char *source, int delimiter)
{
    if (!source) { return NULL; }

    list *l = list_create();

    char *token = strchr(source, delimiter);
    const char *prevPtr = source;

    while (token)
    {
        while (*prevPtr == ' ' || *prevPtr == '.') { prevPtr++; }

        int len = token - prevPtr + 1;

        node *n = string_node_create(prevPtr, len);

        list_insert_back(l, n);

        prevPtr = token;
        token = strchr(token + 1, delimiter);
    }

    while (*prevPtr == ' ' || *prevPtr == '.') { prevPtr++; }

    if((unsigned long)(prevPtr-source) < strlen(source))
    {
        node *n = string_node_create(prevPtr, strlen(source) - (prevPtr - source) + 1);
        list_insert_back(l, n);
    }

    return l;
}

int main()
{
    list *l = split_string("Hello world. This is a sentence. This is another sentence", '.');
    list_print(l, string_node_print);
    list_free(l);
}

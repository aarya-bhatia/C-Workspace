#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

struct _node
{
    void *data;
    struct _node *next;
};

typedef struct _node node;

node *create_node(int val)
{
    node *n = (node *) malloc(sizeof(node));
    n->data = malloc(sizeof(int));  
    memcpy(n->data, (void *)&val, sizeof(int));
    n->next = NULL;

    return n;
}

node *list_insert(node *header, node *n)
{
    if(!header)
    {
        return n;
    }

    if(!n)
    {
        return header;
    }

    node *itr;
    itr = header;

    while(itr->next) itr = itr->next;

    itr->next = n;
    return header;
}

void free_node(node *n)
{
    free(n->data);
    free(n);
}

void free_list(node *head)
{
    node *itr = head;
    
    while(itr)
    {
        node *tmp = itr->next;
        free_node(itr);
        itr=tmp;
    }
}

void print_list(node *head, void (*fptr)(node *n))
{
    node *itr = head;

    while(itr)
    {
        fptr(itr);
        itr = itr->next;
    }
}

void node_print(node *n)
{
    if(!n)return;

    printf("%d\n", *(int *)n->data);
}

node *create_matrix(int m, int n, int **arr)
{
    node *rows = NULL;

    for(int i = 0; i < m; i++)
    {
        node *cols = NULL;

        for(int j = 0; j < n; j++)
        {
            cols = list_insert(cols, create_node(arr[i][j]));
        }

        node *n = (node *)malloc(sizeof(node));
        n->data = (void *)cols;
        n->next = NULL;

        rows = list_insert(rows, n);
    }

    return rows;
}

void test_matrix()
{
    int arr[3][2] = {
        {0, 1},
        {2, 3},
        {4, 5}
    };

    node *mat = create_matrix(3, 2, arr);

    for(node *row = mat; row; row = row->next)
    {
        node *list = (node *)row->data;

        for(node *col = list; col; col = col->next)
        {
            printf("%d ", *(int *)col->data);
            // free(col->data);
        }
        printf("\n");
    }

}

int main(int argc, char *argv[])
{
    node *head = list_insert(NULL, create_node(1));
    head = list_insert(head, create_node(2));
    head = list_insert(head, create_node(3));
    head = list_insert(head, create_node(4));

    print_list(head, node_print);
    free_list(head);

    test_matrix();
}

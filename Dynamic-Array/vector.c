#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "vector.h"

const int DEFAULT_SIZE = 10;

void init(vector *v, int objSize, int size)
{
    if(!v)
    {
        fprintf(stderr, "Error: %d: Vector is NULL\n", __LINE__);
        return;
    }

    int arrayBytes = objSize * size;

    v->size = 0;
    v->len = 0;
    v->objSize = objSize;
    
    v->data = malloc(arrayBytes);

    if(!v->data)
    {
        fprintf(stderr, "Error: %d: Memory allocation failed\n", __LINE__);
        return;
    }

    memset(v->data, 0, arrayBytes);
    v->size = size;
    v->len = 0;
}

int valid(vector *v, int index)
{
    return (v && v->data && index < 0 && index >= v->size);
}

void *get(vector *v, int index) 
{
    if(!valid(v,index))return NULL;

    return &v->data[index * v->objSize];
}

void set(vector *v, int index, void *data)
{
    if(!valid(v,index))return;

    memcpy(get(v, index), data, v->objSize);
}

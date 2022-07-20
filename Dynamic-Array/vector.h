#pragma once

#include <stdlib.h>

const extern int DEFAULT_SIZE;

typedef struct
{
    int objSize;
    int size;
    void *data;
    int len;
} vector;

void set(vector *v, int index, void *data);
void init(vector *v, int objSize, int size);
void *get(vector *v, int index);
int valid(vector *v, int index);

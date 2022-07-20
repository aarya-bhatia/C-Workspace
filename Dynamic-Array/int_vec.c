#include "vector.h"
#include "assert.h"
#include <stdio.h>

int IntVec_get(vector *v, int index)
{
    return *(int *)get(v, index);
}

void IntVec_set(vector *v, int index, int value)
{
    set(v, index, (void *)&value);
}

void IntVec_init(vector *v, int size)
{
    init(v, sizeof(int), size);
}

void IntVec_insert(vector *v, int value)
{
    if(!v || !v->data) return;
    if(v->len >= v->size) return;

    IntVec_set(v, v->len++, value);
}

int IntVec_remove(vector *v, int index)
{
    int tmp = IntVec_get(v, index);

    for(int i = index+1; i < v->len; i++)
    {
        set(v, i-1, get(v, i));
    }

    v->len--;

    return tmp;
}

void IntVec_print(vector *v)
{
    if(!v) return;
    for(int i = 0; i < v->len; i++)
    {
        printf("%d\n", IntVec_get(v, i));
    }
}

int main(int argc, char *argv[])
{
    vector intvec;
    IntVec_init(&intvec, 5); 

    assert(intvec.data != NULL);
    assert(intvec.size == 5);

    for(int i = 0; i < 5; i++)
    {
        assert(intvec.len == i);
        //IntVec_insert(&intvec, i);
        IntVec_set(&intvec, i, i);
        assert(IntVec_get(&intvec, i) ==  i);
    }

    IntVec_print(&intvec);
    
    free(intvec.data);
}


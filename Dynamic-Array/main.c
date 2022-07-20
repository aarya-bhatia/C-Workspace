#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "vector.h"

int main(int argc, char *argv[])
{
    vector v;

    int x = 3;
    init(&v, sizeof(int), 10);

    assert(v.data != NULL);
    assert(v.len == 0);
    assert(v.size == 10);

    set(&v, 0, (void *) &x);

    assert(*(int *) get(&v, 0) == x);

    printf("%d\n", *(int *) get(&v, 0));

    free(v.data);

    // int x2 = 4;
    // set(&v, 1, (void *)&x2);

    // int y = *(int *)get(&v, 0); 
    // int y2 = *(int *)get(&v, 1); 

    // assert(&y == &x);
    // assert(&y2 == &x2);

    return 0;
}

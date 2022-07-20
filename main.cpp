#include <stdio.h>
#include <assert.h>

#include "HashMap.h"
#include "HashSet.h"

int main()
{
    printf("Hello, world!\n");

    MyHashMap *obj = new MyHashMap();
    obj->put(2, 4);
    obj->put(3, 0);
    obj->put(9, 1);
    obj->put(8, 2);
    obj->put(7, 3);
    assert(obj->get(2) == 4);
    assert(obj->get(7) == 3);
    assert(obj->get(4) == -1);
    obj->remove(2);
    assert(obj->get(2) == -1);

    return 0;
}
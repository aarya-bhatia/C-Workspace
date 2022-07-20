#include <iostream>

struct Entity
{
    const char *name;
    int c;
};

struct Compare
{
    int operator()(const Entity &e, const Entity &o)
    {
        return strcmp(e.name, o.name);
    }
};

void foo(Entity &e, Entity &e2, Compare c)
{
    if (c(e, e2) > 0)
    {
        e.c++;
    }
    else
    {
        e2.c++;
    }
}

int main()
{
    Entity e1 = {"A", 0};
    Entity e2 = {"Z", 0};
    foo(e1, e2, Compare());
    assert(e1.c != e2.c);
}

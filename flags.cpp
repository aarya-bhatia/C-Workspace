#include <iostream>
#include <assert.h>
using namespace std;

int main()
{
    int f = 2;
    int f2 = 4;
    int e = 0;
    e = e | f;
    e = e | f2;
    assert(e);
    cout << e << endl;
    assert(e & f);
    cout << (bool)(e & f) << endl;
    assert(e & f2);
    cout << (bool)(e & f2) << endl;
}
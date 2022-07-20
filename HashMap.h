#include <iostream>
#include <assert.h>
#include <vector>
#include <list>
#include <utility>

using namespace std;

class MyHashMap
{
public:
    MyHashMap()
    {
        table.resize(13);
    }

    void put(int key, int value)
    {

        if (table.size() > table.capacity() / 2)
        {
            resize(2 * table.capacity());
        }

        list<pair<int, int>> &row = table[key % table.capacity()];

        for (auto it = row.begin(); it != row.end(); it++)
        {
            if (it->first == key)
            {
                it->second = value;
                return;
            }
        }

        row.push_back(make_pair(key, value));
    }

    int get(int key)
    {

        list<pair<int, int>> &row = table[key % table.capacity()];

        for (auto it = row.begin(); it != row.end(); it++)
        {
            if (it->first == key)
                return it->second;
        }

        return -1;
    }

    void remove(int key)
    {

        list<pair<int, int>> &row = table[key % table.capacity()];

        for (auto it = row.begin(); it != row.end(); it++)
        {
            if (it->first == key)
            {
                row.erase(it);
                break;
            }
        }
    }

    void print()
    {
        cout << "[ ";
        for(size_t i = 0; i < table.capacity(); i++)
        {
            if(!table[i].empty())
            {
                for(auto it = table[i].begin(); it != table[i].end(); it++)
                {
                    cout << "[" << it->first << "," << it->second << "] ";
                }
            }
        }
        cout << "]\n";
    }

private:
    vector<list<pair<int, int>>> table;

    void resize(int newCapacity)
    {
        vector<list<pair<int, int>>> newTable;
        newTable.reserve(newCapacity);

        for(size_t i = 0; i < table.capacity(); i++)
        {
            newTable[i % newCapacity].insert(newTable[i % newCapacity].begin(), table[i].begin(), table[i].end());
        }

        table = newTable;
    }

};
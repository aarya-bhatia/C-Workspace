#include <bits/stdc++.h>

/*
A string is said to be a special string if either of two conditions is met:

All of the characters are the same, e.g. aaa.
All characters except the middle one are the same, e.g. aadaa.
A special substring is any substring of a string which meets one of those criteria. Given a string, determine how many special substrings can be formed from it.

Complete the substrCount function in the editor below.

substrCount has the following parameter(s):
int n: the length of string s
string s: a string
Returns
- int: the number of special substrings

Each character of the string is a lowercase English letter.
*/

using namespace std;

int is_special(size_t start, size_t end, string s)
{
    for (size_t i = start, j = end - 1; i < j; i++, j--)
    {
        if(s[i] != s[j])
        {
            return 0;
        }
    }

    return 1;
}

long count(size_t start, size_t end, string s)
{
    if(start == end)
    {
        return 1L;
    }

    if(start > end)
    {
        return 0L;
    }

    size_t mid = start + (end-start)/2;

    return is_special(start, end, s) + count(start, mid, s) + count(mid, end, s);
}

long substrCount(int n, string s)
{
    return count(0,n-1,s);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

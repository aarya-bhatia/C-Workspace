/**
 * The array-form of an integer num is an array representing its digits in left to right order.
 * For example, for num = 1321, the array form is [1,3,2,1].
 * Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
*/

#pragma once

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int carry = k;

        for (int i = num.size() - 1; i >= 0; i--)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] = num[i] % 10;
        }

        while (carry)
        {
            num.insert(num.begin(), carry % 10);
            carry = carry / 10;
        }

        return num;
    }
};
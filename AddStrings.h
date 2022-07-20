/**
 * @file AddStrings.h
 * @author Aarya Bhatia
 * @brief Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
 * @version 0.1
 * @date 2021-12-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <string>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string large;
        string small;
        if (num1.length() > num2.length())
        {
            large = num1;
            small = num2;
        }
        else
        {
            large = num2;
            small = num1;
        }

        int carry = 0;

        int smallItr = small.length() - 1;
        int largeItr = large.length() - 1;

        while (smallItr >= 0)
        {
            int c1 = small[smallItr] - '0';
            int c2 = large[largeItr] - '0';

            int sum = c1 + c2 + carry;
            carry = sum / 10;
            int digit = sum % 10;

            large[largeItr] = '0' + digit;

            smallItr--;
            largeItr--;
        }

        while (largeItr >= 0 && carry)
        {
            int c = large[largeItr] - '0';
            int sum = c + carry;
            int digit = sum % 10;
            carry = sum / 10;

            large[largeItr] = '0' + digit;

            largeItr--;
        }

        if (carry)
        {
            large = (char)('0' + carry) + large;
        }

        return large;
    }
};
#pragma once

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool checkRow[9][9];
        bool checkCol[9][9];
        bool checkBox[9][9];

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                checkRow[i][j] = false;
                checkCol[i][j] = false;
                checkBox[i][j] = false;
            }
        }

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                int b = 3 * (row / 3) + (col / 3);

                printf("row=%d, col=%d, box=%d\n", row, col, b);

                if (board[row][col] != '.')
                {
                    int val = board[row][col] - '1';

                    if (checkRow[row][val])
                        return false;
                    if (checkCol[col][val])
                        return false;
                    if (checkBox[b][val])
                        return false;

                    checkRow[row][val] = true;
                    checkCol[col][val] = true;
                    checkBox[b][val] = true;
                }
            }
        }

        return true;
    }
};
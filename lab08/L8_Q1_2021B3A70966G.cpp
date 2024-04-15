#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int minMaxRow = INT_MAX;
    int minMaxCol = INT_MAX;

    for (int i = 0; i < rows; i++)
    {
        int maxRow = INT_MIN;
        int curRow = 0;
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
            {
                curRow++;
            }
            else
            {
                curRow = 0;
            }
            maxRow = max(maxRow, curRow);
        }
        minMaxRow = min(minMaxRow, maxRow);
    }

    for (int j = 0; j < cols; j++)
    {
        int maxCol = INT_MIN;
        int curCol = 0;
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][j] == '1')
            {
                curCol++;
            }
            else
            {
                curCol = 0;
            }
            maxCol = max(maxCol, curCol);
        }
        minMaxCol = min(minMaxCol, maxCol);
    }

    return minMaxRow * minMaxCol;
}
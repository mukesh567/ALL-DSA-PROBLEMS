
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &arr, int val)
{
    for (int i = 0; i < arr[0].size(); i++)
    {
        // for row check
        if (arr[row][i] == val)
        {
            return false;
        }

        // for col check
        if (arr[i][col] == val)
        {
            return false;
        }

        // for matrix check
        if (arr[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool sudokuSolve(vector<vector<int>> &arr)
{
    int n = arr[0].size();

    // for track matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // cell empty
            if (arr[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, arr, val))
                    {
                        arr[row][col] = val;

                        // recursive call
                        bool solPossible = sudokuSolve(arr);
                        if (solPossible)
                        {
                            return true;
                        }
                        else
                        {
                            // back track
                            arr[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printSudoku(vector<vector<int>> arr)
{
    int n = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (sudokuSolve(arr))
    {
        printSudoku(arr);
    }
    else
    {
        cout << "No solution exits ! " << endl;
    }

    return 0;
}
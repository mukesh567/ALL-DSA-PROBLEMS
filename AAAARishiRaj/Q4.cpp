
// Q4 . Write a program to perform matrix multiplication ?

#include <bits/stdc++.h>
using namespace std;

void multiplicationMat(int arr1[][30], int row, int col, int arr2[][30], int multiArr[][30])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            multiArr[i][j] = 0;
            for (int k = 0; k < col; k++)
            {
                multiArr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << multiArr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr1[30][30], arr2[30][30], multiArr[30][30];

    int row, col;
    cout << "Enter the number of row and number of col : ";
    cin >> row >> col;


    cout << "First matrix elements is : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr1[i][j];
        }
    }

    cout << "Second matrix elements is : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr2[i][j];
        }
    }

    multiplicationMat(arr1, row, col, arr2, multiArr);

    return 0;
}
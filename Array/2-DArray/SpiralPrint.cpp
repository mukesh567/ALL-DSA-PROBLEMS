
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[][4], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printSpiral(int arr[][4], int m, int n)
{
    int rowStart = 0;
    int rowEnd = m - 1;
    int colStart = 0;
    int colEnd = n - 1;
    int count = 0;
    int total = m * n;
    while (count < total)
    {
        // print starting row

        for (int index = colStart; count < total && index <= colEnd; index++)
        {
            cout << arr[rowStart][index] << " ";
            count++;
        }
        rowStart++;

        // print ending col

        for (int index = rowStart; count < total && index <= rowEnd; index++)
        {
            cout << arr[index][colEnd] << " ";
            count++;
        }
        colEnd--;

        // print ending row

        for (int index = colEnd; count < total && index >= colStart; index--)
        {
            cout << arr[rowEnd][index] << " ";
            count++;
        }
        rowEnd--;

        // print starting col

        for (int index = rowEnd; count < total && index >= rowStart; index--)
        {
            cout << arr[index][colStart] << " ";
            count++;
        }
        colStart++;
    }
}

int main()
{
    int arr[3][4];

    cout << "Enter your input : ";
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
    cout << "printing the array : " << endl;
    printArray(arr, 3, 4);

    cout << "Spiral printing array is : ";
    printSpiral(arr, 3, 4);
    return 0;
}
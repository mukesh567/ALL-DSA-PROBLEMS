#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cout << "Enter the rows and colmns\n";
    cin >> m >> n;
    int arr[m][n];
    cout << "Enter the elements of array\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<"printing array are:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"arrays spiral order are printing\n";
    int row_start = 0, row_end = m - 1, colm_start = 0, colm_end = n - 1;
    while (row_start <= row_end && colm_start <= colm_end)
    {
        for (int col = colm_start; col <= colm_end; col++)
        {

            cout << arr[row_start][col] << " ";
        }
        row_start++;
        for (int row = row_start; row <= row_end; row++)
        {
            cout << arr[row][colm_end] << " ";
        }
        colm_end--;
        for (int col = colm_end; col >= colm_start; col--)
        {
            cout << arr[row_end][col] << " ";
        }
        row_end--;
        for (int row = row_end; row >= row_start; row--)
        {
            cout << arr[row][colm_start] << " ";
        }
        colm_start++;
    }
    return 0;
}
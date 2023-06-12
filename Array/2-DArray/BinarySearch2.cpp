

// ROW AND COL WISE SORTED ARRAY

#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[][4], int m, int n, int target)
{
    int rowIndex = 0;
    int colIndex = n - 1;

    while (rowIndex <= m && colIndex >= 0)
    {

        int element = arr[rowIndex][colIndex];

        if (element == target)
        {
            return 1;
        }
        if (element < target)

        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return 0;
}

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

    cout << "Printing the array : " << endl;
    printArray(arr, 3, 4);

    int target;
    cout << "Enter target who you want to search : ";
    cin >> target;

    if (binarySearch(arr, 3, 4, target))
    {
        cout << "Element Found!" << endl;
    }
    else
    {
        cout << "Element Not found!" << endl;
    }

    return 0;
}
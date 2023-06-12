
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

int main()
{

    int arr[3][4];
    // int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr[3][4]={{1,4,7},{2,5,6},{3,8,9}};

    // taking input row-wise
    cout << "Enter your input : ";
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
    cout << "Row wise print array : " << endl;
    printArray(arr, 3, 4);



    // taking input col-wise
    cout << "Enter your input : ";
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            cin >> arr[row][col];
        }
    }
    cout << "col wise print array : " << endl;
    printArray(arr, 3, 4);
    return 0;
}
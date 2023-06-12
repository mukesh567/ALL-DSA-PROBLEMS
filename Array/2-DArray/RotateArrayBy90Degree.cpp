
#include <bits/stdc++.h>
using namespace std;

void rotate90Clockwise(int arr[][3], int m, int n)
{
    //colmn wise print karayenge or sabse pehle last row ko print karana hai

    for (int j = 0; j < n; j++)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray(int arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << endl;
    cout << "The array is : " << endl;
    printArray(arr);

    cout << endl;
    cout << "90 Degree rotatete array is : " << endl;
    rotate90Clockwise(arr, 3, 3);

    return 0;
}
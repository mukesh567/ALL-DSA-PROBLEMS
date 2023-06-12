

#include <bits/stdc++.h>
using namespace std;

void printLargestRowSumNumber(int arr[][3])
{
    int max = INT_MIN;
    int rowIndex = -1;

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;

        for (int j = 0; j < 3; j++)
        {

            sum += arr[i][j];
        }
        if (max < sum)
        {
            max = sum;
            rowIndex = i;
        }
    }

    cout << "Maximum sum of this array is : " << max << endl;
    cout << "The row number  whose sum is largest : " << rowIndex << endl;
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
    int arr[3][3] = {1, 5, 3, 2, 4, 6, 8, 9, 10};

    cout << endl;
    cout << "The array is : " << endl;
    printArray(arr);

    cout << endl;
    printLargestRowSumNumber(arr);
    cout << endl;

    return 0;
}
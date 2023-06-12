

#include <bits/stdc++.h>
using namespace std;

void printLargestcolSumNumber(int arr[][3])
{
    int max = INT_MIN;
    int colIndex = -1;

    for (int j = 0; j < 3; j++)
    {
        int sum = 0;

        for (int i = 0; i < 3; i++)
        {

            sum += arr[i][j];
        }
        if (max < sum)
        {
            max = sum;
            colIndex = j;
        }
    }

    cout << "Maximum sum of this array is : " << max << endl;
    cout << "The col number  whose sum is largest : " << colIndex << endl;
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

    
    printLargestcolSumNumber(arr);
    cout << endl;

    return 0;
}
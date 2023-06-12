

#include <bits/stdc++.h>
using namespace std;

void printColWiseSum(int arr[][3])
{

    for (int j = 0; j < 3; j++)
    {
        int sum = 0;

        for (int i = 0; i < 3; i++)
        {

            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
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

    cout << "Print the col wise sum : " << endl;
    printColWiseSum(arr);

    return 0;
}
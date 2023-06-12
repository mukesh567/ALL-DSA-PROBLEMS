
#include <bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][3], int target)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
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

    cout << "Our matrix is : " << endl;
    printArray(arr);

    int target;
    cout << "Enter your key who you want to search in this array : ";
    cin >> target;


    if (isPresent(arr, target))
    {
        cout << "Element present in this array!";
    }
    else
    {
        cout << "Element not found!";
    }

    return 0;
}
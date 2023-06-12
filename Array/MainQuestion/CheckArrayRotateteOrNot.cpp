
#include <bits/stdc++.h>
using namespace std;

bool RotateOrNot(int arr[], int n)
{
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }

    if (arr[n - 1] > arr[0])
    {
        count++;
    }
    
    return count <= 1;
}

int main()
{
    int arr[5] = {3, 4, 5, 1, 2};
    cout << endl;

    if (RotateOrNot(arr, 5))
    {
        cout << "Given Array is Rotatete !" << endl;
    }
    else
    {
        cout << "Array is not rotatete !" << endl;
    }
    cout << endl;
    return 0;
}
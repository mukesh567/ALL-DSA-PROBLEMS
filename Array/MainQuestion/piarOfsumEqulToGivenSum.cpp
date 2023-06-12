
#include <bits/stdc++.h>
using namespace std;

void PairOfSum(int arr[], int n, int sum)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {

                cout << arr[i] << " " << arr[j] << " ";
            }
        }
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum;
    cout << "Enter the sum who you want to make pair :  ";
    cin >> sum;

    PairOfSum(arr, n, sum);
}
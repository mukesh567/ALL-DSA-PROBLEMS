
#include <bits/stdc++.h>
using namespace std;

void findPair(int arr[], int n, int sum)
{
    sort(arr, arr + n);

    int low = 0, high = n - 1;

    while (low < high)
    {
        if (arr[low] + arr[high] == sum)
        {
            cout << "Pair found (" << arr[low] << ", " << arr[high] << ")" << endl;
            return;
        }
        else if (arr[low] + arr[high] < sum)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
}

int main()
{
    int arr[6] = {6, 5, 4, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum;
    cout << "Enter the sum : ";
    cin >> sum;

    findPair(arr, n, sum);
}
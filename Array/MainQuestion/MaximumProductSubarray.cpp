
#include <bits/stdc++.h>
using namespace std;

int maxProduct(int *arr, int n)
{
    int maxi = arr[0];
    int mini = arr[0];
    int ans = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(maxi, mini);
        }

        maxi = max(arr[i], maxi * arr[i]);
        mini = min(arr[i], mini * arr[i]);
        ans = max(ans, maxi);
    }

    return ans;
}

int main()
{
    int arr[6] = {2, 3, 4, 5, -1, 0};

    cout << endl
         << "Maximum product subarray is : " << maxProduct(arr, 5) << endl
         << endl;

    return 0;
}
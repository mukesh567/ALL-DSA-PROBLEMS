
#include <bits/stdc++.h>
using namespace std;

int findMid(int *arr1, int *arr2, int n)
{
    // for first array
    int i = n - 1;

    // for second array
    int j = 0;

    // loop when first arrays elements are greater than the second array
    while (arr1[i] > arr2[j] && j < n && i > -1)
    {
        swap(arr1[i--], arr2[j++]);
    }

    // sort both of the arrays
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);

    // find answer
    int ans = (arr1[n - 1] + arr2[0]) / 2;
    return ans;
}

int main()
{
    int n = 5;
    int arr1[n] = {1, 12, 15, 26, 38};
    int arr2[n] = {2, 13, 17, 30, 45};

    cout << endl
         << endl
         << "Median of two arrays is : " << findMid(arr1, arr2, n) << endl
         << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int kthLargestSubarray(int *arr, int n, int k)
{
    vector<int> sumStore;

    // step-1 store the sum of the all possible subArray
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];

            sumStore.push_back(sum);
        }
    }

    // step -2 sort the sumStore array
    sort(sumStore.begin(), sumStore.end());

    // step-3 return the kth largest sum
    int size = sumStore.size();
    return sumStore[size - k];
}

int main()
{
    int arr[] = {20, -5, -1};

    int n = sizeof(arr) / sizeof(arr[0]);

    // find second largest sum subArray
    int k = 3;

    int ans = kthLargestSubarray(arr, n, k);

    cout << endl
         << "Kth largest sum subarray is : " << ans << endl<<endl;

    return 0;
}
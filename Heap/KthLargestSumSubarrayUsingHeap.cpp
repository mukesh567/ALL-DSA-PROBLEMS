

#include <bits/stdc++.h>
using namespace std;

int kthLargestSubarray(int *arr, int n, int k)
{

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {

        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];

            if (minHeap.size() < k)
            {
                minHeap.push(sum);
            }
            
            else if (minHeap.top() < sum)
            {
                minHeap.pop();
                minHeap.push(sum);
            }
        }

    }

    return minHeap.top();
}

int main()
{
    int arr[] = {1,2,7,7,4,3,6};

    int n = sizeof(arr) / sizeof(arr[0]);

    // find second largest sum subArray
    int k = 3;

    int ans = kthLargestSubarray(arr, n, k);

    cout << endl
         << "Kth largest sum subarray is : " << ans << endl
         << endl;

    return 0;
}
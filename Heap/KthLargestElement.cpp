

#include <bits/stdc++.h>
using namespace std;

int kthLargestEle(int *arr, int n, int k)
{
    // step - 1: first k element ka minHeap bana do
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step - 2: heap k top  se compare karne par
    // for remaining elements
    for (int i = k; i < n; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step - 3: jo heap ka top hoga vo apna kth largest hoga
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[] = {7, 10, 4, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    int ans = kthLargestEle(arr, n, k);

    cout << endl
         << endl
         << "Kth largest element is : " << ans << endl
         << endl;
    return 0;
}
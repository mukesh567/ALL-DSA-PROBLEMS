
#include <bits/stdc++.h>
using namespace std;

int kthSmallestEle(int *arr, int n, int k)
{
    // step - 1: first k element ka maxHeap bana do
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step - 2: heap k top  se compare karne par
    // for remaining elements
    for (int i = k; i < n; i++)
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step - 3: jo heap ka top hoga vo apna kth smallest hoga
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[] = {7, 10, 4, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int ans = kthSmallestEle(arr, n, k);

    cout << endl
         << endl
         << "Kth smallest element is : " << ans << endl
         << endl;
    return 0;
}
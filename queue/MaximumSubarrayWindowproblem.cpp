#include <deque>
#include <iostream>

using namespace std;

void solve(int arr[], int n, int k)
{
    deque<int> q;

    // first k window
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && arr[q.back()] <= arr[i])
        {
            q.pop_back();
        }

        q.push_back(i);
    }

    cout << arr[q.front()] << " ";

    // agli windows k liye
    for (int i = k; i < n; i++)
    {
        // removel element
        while (!q.empty() && i - q.front() >= k)
        {
            q.pop_front();
        }

        // addition a element
        while (!q.empty() && arr[q.back()] <= arr[i])
        {
            q.pop_back();
        }

        q.push_back(i);

        cout << arr[q.front()] << " ";
    }
}

// Driver Code
int main()
{
    int arr[] = { 1 ,2,7,7,4,3,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    solve(arr, n, k);

    return 0;
}
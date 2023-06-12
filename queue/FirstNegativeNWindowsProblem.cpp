
// window k size me first negative number ko print karna hai

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int *arr, int n, int k)
{

    deque<int> dq;
    vector<int> ans;

    // first k process
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // stores the first k window ans
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remainning elements
    for (int i = k; i < n; i++)
    {

        // removel from the front
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // agla element ka addition
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        // ans store
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{

    int arr[] = {-8, 2, 3, -6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    vector<int> ans = solve(arr, n, k);
    for (auto element : ans)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
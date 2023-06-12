
#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &arr)
{
    int sum = 0;
    for (int i : arr)
    {
        sum += i;
    }

    return sum;
}

int solve(int arr[], int n)
{
    // store all vector according to index
    vector<vector<int>> v(n);

    // push first value as a first array
    v[0].push_back(arr[0]);

    // rest of task
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] > arr[j]) && (maxSum(v[i]) < maxSum(v[j])))
            {
                v[i] = v[j];
            }
        }

        v[i].push_back(arr[i]);
    }

    // result vector
    vector<int> res = v[0];

    for (vector<int> m : v)
    {
        if (maxSum(m) > maxSum(res))
        {
            res = m;
        }
    }

    int ans = maxSum(res);

    return ans;
}

int maxSumIS(int arr[], int n)
{
    return solve(arr, n);
}

int main()
{
    int n = 5;
    int arr[n] = {1, 101, 2, 3, 100};

    cout << maxSumIS(arr, n) << endl;
    return 0;
}
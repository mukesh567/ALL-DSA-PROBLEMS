
#include <bits/stdc++.h>
using namespace std;

// kaden's algorithm

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum > max)
        {
            max = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << max << endl;
    return 0;
}
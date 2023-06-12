
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int k;
    cin >> k;

    // sort the array
    priority_queue<int, vector<int>,greater<int>> p;

    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }
    
    int ans, i = 1;

    while (!p.empty())
    {
        if (i == k)
        {
            ans = p.top();
        }
        i++;
        p.pop();
    }

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<int, vector<int>, greater<int>> p;

    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }

    int ans = 0;

    while (p.size() > 1)
    {
        int first = p.top();
        p.pop();
        int second = p.top();
        p.pop();
        int sum = first + second;

        ans += sum;
        p.push(sum);
    }

    cout << ans << endl;
    return 0;
}
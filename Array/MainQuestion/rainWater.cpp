
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 3 1 2 4 0 1 3 2          ans=8
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int left[n];
    int right[n];

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(right[i], left[i]) - arr[i]);
    }
    cout << ans << endl;
    return 0;
}
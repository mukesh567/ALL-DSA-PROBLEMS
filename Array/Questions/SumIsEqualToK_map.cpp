
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1 5 7 1 ,k=6 : ans=2
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> n;
    }
    int k;
    cin >> k;
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int x = k - arr[i];
        if (m[x] == 0)
        {
            m[arr[i]]++;
        }
        else
        {
            count += m[x];
            m[arr[i]]++;
        }
    }
  cout << count << endl;
    return 0;
}

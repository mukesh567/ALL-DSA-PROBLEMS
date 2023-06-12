
#include <bits/stdc++.h>
using namespace std;

int main()
{ // 1 5 8 4 7 6 5 3 1 => 1 5 8 5 1 3 4 6 7
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Before the Next_Permutation : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int idx = -1;
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] > a[i - 1])
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        reverse(a.begin(), a.end());
    }
    else
    {
        int prev = idx;
        for (int i = idx + 1; i < n; i++)
        {
            if (a[i] > a[idx - 1] && a[i] <= a[prev])
            {
                prev = i;
            }
        }
        swap(a[idx - 1], a[prev]);
        reverse(a.begin() + idx, a.end());
    }
    cout << "After the Next_Permutation : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
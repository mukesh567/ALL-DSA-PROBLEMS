
#include <bits/stdc++.h>
using namespace std;

void Subset(vector<int> a, vector<int> empty, int index)
{
    if (index >= a.size())
    {
        for (auto i : empty)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    Subset(a, empty, index + 1);
    empty.push_back(a[index]);
    Subset(a, empty, index + 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Subset(a, {}, 0);
    return 0;
}
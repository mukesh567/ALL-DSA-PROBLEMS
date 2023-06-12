#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int, greater<int>> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(3);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
}
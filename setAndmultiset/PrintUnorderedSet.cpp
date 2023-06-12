
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(4);
    s.insert(1);
    s.insert(2);
    s.insert(9);
    s.insert(3);
    s.insert(5);

    cout << "Before the deletion : ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    // s.erase(2);
    // s.erase(s.begin());
    // cout << "After the deletion : ";
    // for (auto i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}
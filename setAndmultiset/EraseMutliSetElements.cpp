#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    cout << "Print the multiSet: ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "After erasing elements: ";
    s.erase(3);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "after erasing only One elemnts: ";
    s.erase(s.lower_bound(3));
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
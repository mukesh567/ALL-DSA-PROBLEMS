
#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(3);

    // s.erase(2);
    s.erase(s.begin());
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

}
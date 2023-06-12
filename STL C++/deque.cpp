
// #include <iostream>
// #include <deque>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> s;

    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_front(0);
    cout << "Deque element is:: ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Second index element is::" << s.at(2) << endl;
    cout << "Front = " << s.front() << endl;
    cout << "Back = " << s.back() << endl;
    cout << "Empty or not = " << s.empty() << endl;

    cout << "Before erase:: ";
    cout << "size = " << s.size() << endl;
    s.erase(s.begin(), s.begin() + 2);
    cout << "After erase:: ";
    cout << "size = " << s.size() << endl;

    cout << "Deque element is:: ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    // s.pop_back();
    // cout << "Deque element is:: ";
    // for (auto i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // s.pop_front();
    // cout << "Deque element is:: ";
    // for (auto i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}
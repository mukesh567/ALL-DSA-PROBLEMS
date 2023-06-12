
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> s;
    s.push_back(2);
    s.push_front(1);
    s.push_back(3);

    cout << "Print list element is:: ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    list<int> m(5, 100);
    cout << "Printing list element is:: ";
    for (auto i : m)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Front = " << s.front() << endl;
    cout << "Back = " << s.back() << endl;
    cout << "Empty or not = " << s.empty() << endl;
    cout << "size = " << s.size() << endl;

    s.erase(s.begin());
    // s.pop_front();
    cout << "After erase list element is:: ";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
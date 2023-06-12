
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    cout << "Print set:";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    cout << "After erase second index element::";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Element found or not:" << s.count(4) << endl;
    cout << "After 2 value print all the value present in set::";
    set<int>::iterator itr = s.find(2);
    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> s;
    s.push_back(2);
    s.push_back(5);
    s.push_back(7);
    s.push_back(9);
    cout << "element present or not::";
    cout << binary_search(s.begin(), s.end(), 5) << endl;
    cout << "Lower bound::" << lower_bound(s.begin(), s.end(), 5) - s.begin() << endl;
    cout << "upper bound::" << upper_bound(s.begin(), s.end(), 5) - s.begin() << endl;

    int a = 78, b = 90;
    cout << "Max::" << max(a, b) << endl;
    cout << "Min::" << min(a, b) << endl;

    swap(a, b);
    cout << a << endl;

    string m = "sugna";
    reverse(m.begin(), m.end());
    cout << m << endl;
    cout << "Before Rotate::";
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "After rotate::";
    rotate(s.begin(), s.begin() + 1, s.end());
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "After sorting::";
    sort(s.begin(), s.end());
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
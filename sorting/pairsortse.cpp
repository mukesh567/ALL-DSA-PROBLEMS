//  Sorting the vector elements on the basis of second element of pairs in ascending order
#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}
int main()
{
    vector<pair<int, int>> s;
    int arr[] = {23, 45, 43, 12, 13};
    int arr1[] = {32, 50, 76, 13, 15};

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        s.push_back(make_pair(arr[i], arr1[i]));
    }
    cout << "before the sorting::" << endl;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << s[i].first << " ";
        cout << s[i].second << endl;
    }
    cout << "After sorting::" << endl;
    sort(s.begin(), s.end(), sortbysec);
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << s[i].first << " ";
        cout << s[i].second << endl;
    }
    return 0;
}
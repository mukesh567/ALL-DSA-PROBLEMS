
#include <bits/stdc++.h>
using namespace std;

void Intersection(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++, j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << ans.size();
}
int main()
{
    vector<int> arr1 = {1, 2, 3};
    int n = arr1.size();
    vector<int> arr2 = {2, 3};
    
    int m = arr2.size();
    
    Intersection(arr1, arr2, n, m);
    return 0;
}
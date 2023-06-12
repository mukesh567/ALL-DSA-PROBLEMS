
#include <bits/stdc++.h>
using namespace std;

void Intersection(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int element = arr1[i];

        for (int j = 0; j < m; j++)
        {
            if (element < arr2[j])
            {
                break;
            }
            if (element == arr2[j])
            {
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
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
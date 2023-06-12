#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, int i, vector<int> &subset, vector<vector<int>> &ans)
{
    // base case
    if (i >= arr.size())
    {
        ans.push_back(subset);
        return;
    }

    // first we include and calling fun for rest of the ele
    subset.push_back(arr[i]);
    helper(arr, i + 1, subset, ans);
    subset.pop_back();

    // remove duplicate subsets
    while (i + 1 < arr.size() && arr[i] == arr[i + 1])
        i++;

    helper(arr, i + 1, subset, ans);
}

vector<vector<int>> findUniquesubsets(vector<int> &arr)
{
    // first sort the input array
   sort(arr.begin(),arr.end());

    vector<vector<int>> ans;
    vector<int> subset;

    helper(arr, 0, subset, ans);

    // maintain the order so sort it then return
    sort(ans.begin(),ans.end());

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2};

    vector<vector<int>> ans = findUniquesubsets(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
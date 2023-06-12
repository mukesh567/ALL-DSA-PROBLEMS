

#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, int i, int sum, int sumTillNow, vector<int> &subset, vector<vector<int>> &ans)
{
    // base case
    if (sumTillNow == sum)
    {
        ans.push_back(subset);
        return;
    }

    if (sumTillNow > sum )
    {
        return;
    }

    if(i>=arr.size())
    {
        return;
    }

     //first we skip and calling fun for rest of the ele
    helper(arr, i + 1, sum, sumTillNow, subset, ans);

    // second we include and calling fun for rest of the ele and backtrack
    sumTillNow += arr[i];
    subset.push_back(arr[i]);
    helper(arr, i, sum, sumTillNow, subset, ans);

    //backtrack
    sumTillNow -= arr[i];
    subset.pop_back();
}

vector<vector<int>> combinations(vector<int> &arr, int sum)
{
    //sort the input array
    //sort(arr.begin(),arr.end());

    vector<vector<int>> ans;
    vector<int> subset;
    int sumTillNow = 0;

    helper(arr, 0, sum, sumTillNow, subset, ans);

    // maintain the order so sort it then return
    sort(ans.begin(),ans.end());

    return ans;
}

int main()
{

    vector<int> arr = {2, 3, 6,7};

    int sum = 7;

    vector<vector<int>> ans = combinations(arr, sum);

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
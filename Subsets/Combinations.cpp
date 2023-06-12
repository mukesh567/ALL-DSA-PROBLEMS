
#include <bits/stdc++.h>
using namespace std;

void helper(int n, int i, int k, vector<int> &subset, vector<vector<int>> &ans)
{
    // base case
    if (i > n)
    {
        if (k == 0)
        {
            ans.push_back(subset);
        }

        return;
    }

    // first we include and calling fun for rest of the ele
    subset.push_back(i);
    helper(n, i + 1, k - 1, subset, ans);

    // second we exclude and calling fun for rest of the ele
    subset.pop_back();
    helper(n, i + 1, k, subset, ans);
}

vector<vector<int>> combinations(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> subset;

    helper(n, 1, k, subset, ans);

    // maintain the order so sort it then return
    // sort(ans.begin(),ans.end());

    return ans;
}

int main()
{

    // 1 2 3 4
    int n = 4;

    // k=3 k liye litne combination banenge
    int k = 3;

    vector<vector<int>> ans = combinations(n, k);

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
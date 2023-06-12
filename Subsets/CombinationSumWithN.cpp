
#include <bits/stdc++.h>
using namespace std;

void helper(int i, int k, int n, int sumTillNow, vector<int> &subset, vector<vector<int>> &ans)
{

    // base conditions
    if (sumTillNow > n)
    {
        return;
    }

    if (k == 0)
    {
        if (sumTillNow == n)
        {
            ans.push_back(subset);
        }

        return;
    }

    if (i == 10)
    {
        return;
    }

    // picking the element
    sumTillNow += i;
    subset.push_back(i);
    helper(i + 1, k - 1, n, sumTillNow, subset, ans);

    // backtrack
    sumTillNow -= i;
    subset.pop_back();

    // not picking
    helper(i + 1, k, n, sumTillNow, subset, ans);
}

vector<vector<int>> CombiWithN(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> subset;
    int sumTillNow = 0;

    helper(1, k, n, sumTillNow, subset, ans);

    return ans;
}

int main()
{
    int n = 9;
    int k = 3;

    vector<vector<int>> ans = CombiWithN(k, n);

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
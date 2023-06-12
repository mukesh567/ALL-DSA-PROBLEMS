
#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &A, int i, int B, int sumNow, vector<int> &subset,
            vector<vector<int>> &ans)
{
    // base case
    if (sumNow == B)
    {
        ans.push_back(subset);
        return;
    }

    if (sumNow > B)
    {
        return;
    }

    if (i == A.size())
    {
        return;
    }

    // include
    subset.push_back(A[i]);
    sumNow += A[i];
    helper(A, i, B, sumNow, subset, ans);

    // backtrack
    subset.pop_back();
    sumNow -= A[i];

    // skip
    while (i + 1 < A.size() && A[i] == A[i + 1])
        i++;

    helper(A, i + 1, B, sumNow, subset, ans);
}

// combinations whose sum is equal to given number.
vector<vector<int>> UniquecombinationSum(vector<int> &A, int B)
{

    // sort the input array
    //sort(A.begin(), A.end());

    vector<vector<int>> ans;
    vector<int> subset;
    int sumNow = 0;
    helper(A, 0, B, sumNow, subset, ans);

    // sort the ans array
    // sort(ans.begin(),ans.end());

    return ans;
}

int main()
{
    vector<int> arr = {10,1,2,7,6,1,5};

    int sum = 8;

    vector<vector<int>> ans = UniquecombinationSum(arr, sum);

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
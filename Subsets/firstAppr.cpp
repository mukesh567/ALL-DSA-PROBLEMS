
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> helper(vector<int> &A, int i)
{
    // base  case
    if (i >= A.size())
    {
        return {{}};
    }

    // firstly we found out ans like 2,3
    vector<vector<int>> parAns = helper(A, i + 1);
    vector<vector<int>> ans;

    // then push the their answer
    for (vector<int> x : parAns)
    {
        ans.push_back(x);
    }

    // then ith char means 1 push in parAns's front
    // frist temp me daal do ith then temp me parAns daal do
    // then ans me push kar do temp ko

    for (vector<int> x : parAns)
    {
        vector<int> temp;
        temp.push_back(A[i]);

        for (int y : x)
        {
            temp.push_back(y);
        }

        ans.push_back(temp);
    }

    // before return ans sort it
    // ans is correct but order is change thus we sort it
    sort(ans.begin(), ans.end());
    return ans;
}

vector<vector<int>> subsets(vector<int> &A)
{
    return helper(A, 0);
}

int main()
{
    vector<int> A = {1, 2, 3};

    vector<vector<int>> ans = subsets(A);

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
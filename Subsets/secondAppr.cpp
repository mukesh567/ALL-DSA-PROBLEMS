
#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> &A,int i,vector<int> &subset,vector<vector<int>> &ans)
{
    //base case
    if(i>=A.size())
    {
        ans.push_back(subset);
        return;
    }

     // first we include and calling fun for rest of the ele
     subset.push_back(A[i]);
     helper(A,i+1,subset,ans);

     //second we exclude and calling fun for rest of the ele
     subset.pop_back();
     helper(A,i+1,subset,ans);
}


vector<vector<int>> subsets(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> subset;

    helper(A,0,subset,ans);

    // maintain the order so sort it then return
    sort(ans.begin(),ans.end());

    return ans;
}


int main()
{
    vector<int> A = {1,2,3};

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

#include <bits/stdc++.h>
using namespace std;

vector<int> findCommonElements( vector< vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();

    // intialized first row elements with 1 using map
    unordered_map<int,int> mp;
    for(int j=0;j<col;j++)
    {
        mp[mat[0][j]]=1;
    }

    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(mp.find(mat[i][j])!=mp.end() && mp[mat[i][j]]==i)
            {
                mp[mat[i][j]]++;
            }
        }
    }

    vector<int> ans;
    for (pair<int, int> p : mp)
    {
       
        if (p.second == row)
        {
            ans.push_back(p.first);
        }
    }

    return ans;
}

int main()
{
    vector< vector<int>> mat{
                 {5, 3, 4, 7},
                 {0, 0, 3, 5},
                 {1, 3, 8, 5}};

    vector<int> ans = findCommonElements(mat);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
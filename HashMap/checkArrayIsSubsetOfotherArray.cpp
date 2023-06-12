
// find r array is sunset of v
#include <bits/stdc++.h>
using namespace std;

bool checkSubset(vector<int> v , int n ,vector<int> r ,int m)
{
    //create a map for v
    unordered_map<int ,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[v[i]]++;
    }

    // searching for r elements in map
    for(int i=0;i<m;i++)
    {
        if(mp.find(r[i])==mp.end())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int n = v.size();
    vector<int> r = {5,4};
    int m = r.size();

    if (checkSubset(v, n, r, m))
    {
        cout << "Array 2 is a subset of array 1 !" << endl;
    }
    else
    {
        cout << "Array 2 is not a subset of array 1 !" << endl;
    }
    
    return 0;
}
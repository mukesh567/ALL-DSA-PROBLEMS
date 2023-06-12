#include<bits/stdc++.h>
using namespace std;

void printvector(vector <int> &v)
{
    cout<<"Size of vector is::"<<v.size()<<endl;

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main()
{
    int N;
    cout<<"Enter the vectors::"<<endl;
    cin>>N;
    vector<vector<int>>v;
    // vector<int> v[N];

    // for(int i=0;i<N;i++)
    // {
    //     int n;
    //     cout<<"Enter the size of vector element::"<<endl;
    //     cin>>n;
    //     for(int j=0;j<n;j++)
    //     {
    //         int x;
    //         cout<<"Enter vector elements::";
    //         cin>>x;
    //         v[i].push_back(x);
    //     }
    // }
    vector<int> temp;
    for(int i=0;i<N;i++)
    {
        int n;
        cout<<"Enter the size of vector element::"<<endl;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int x;
            cout<<"Enter vector elements::";
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    for(int i=0;i<N;i++)
    {
        printvector(v[i]);
    }
    return 0;
}
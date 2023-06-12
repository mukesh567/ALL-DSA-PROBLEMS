// *
// * *
// * * *
// * * * *
// * * * * *

#include<bits/stdc++.h>
using namespace std;

void pyramidPrint(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter number of rows and cols where till you want to print pyramid : ";
    cin>>n;

    pyramidPrint(n);
    return 0;
}

// * * * * *
// * * * *
// * * *
// * *
// *

#include<bits/stdc++.h>
using namespace std;

void invertPyramidPrint(int n)
{
    for(int i=n;i>=1;i--)
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

    invertPyramidPrint(n);
    return 0;
}
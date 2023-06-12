// * 
// * *
// *   *
// *     *
// * * * * *

#include<bits/stdc++.h>
using namespace std;

void hollowPyramidPrint(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1 || i==j || i==n || j==n)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter number of rows and cols where till you want to print pyramid : ";
    cin>>n;

    hollowPyramidPrint(n);
    return 0;
}
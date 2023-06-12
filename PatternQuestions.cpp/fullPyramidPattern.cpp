//      *
//     * *
//    * * *
//   * * * *
//  * * * * *
// * * * * * * 

#include<bits/stdc++.h>
using namespace std;

void fullPyramidPrint(int n)
{
    for(int i=1;i<=n;i++)
    {
        // first print space 
        for(int space =1;space<=n-i;space++)
        {
            cout<<" ";
        }

        // print star
        for(int j=1;j<=2*i-1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter number of rows and cols where till you want to print fill pyramid : ";
    cin>>n;

   fullPyramidPrint(n);
    return 0;
}
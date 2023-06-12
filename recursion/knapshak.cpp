
#include<bits/stdc++.h>
using namespace std;
int knapshak(int value[],int wt[],int n,int W)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(wt[n-1]>W)
    {
        return knapshak(value,wt,n-1,W);
    }
    return max(knapshak(value,wt,n-1,W-wt[n-1])+value[n-1],knapshak(value,wt,n-1,W));
}
int main()
{
    int value[]={100,50,150};
    int wt[]={10,20,30};
    int W=50;
    cout<<knapshak(value,wt,3,W)<<endl;
    return 0;
}
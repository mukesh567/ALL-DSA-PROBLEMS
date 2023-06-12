
#include<bits/stdc++.h>
using namespace std;

int numberOfjumps(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }

    return numberOfjumps(n-1)+numberOfjumps(n-2)+numberOfjumps(n-3);
}

int main()
{
    int n;
    cout<<"Enter the stair : ";
    cin>>n;

    cout<<"Number of jumps : "<<numberOfjumps(n);
    return 0;
}
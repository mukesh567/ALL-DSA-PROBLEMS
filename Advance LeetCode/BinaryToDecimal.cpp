
#include<bits/stdc++.h>
using namespace std;
int BinaryToDecimal(int n)

{
    int i=0,ans=0;
    while(n!=0)
    {
        int digit=n%10;
        if(digit==1)
        {
            ans=ans+pow(2,i);
        }
        n=n/10;
        i++;
    }
    return ans;
}

int main()
{
    int n;cin>>n;
    cout<<BinaryToDecimal(n)<<endl;
    return 0;
}


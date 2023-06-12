
#include<bits/stdc++.h>
using namespace std;
void inc(int n)
{
    if(n==1)
    {
        cout<<"1"<<endl;
        return ;
    }
    inc(n-1);
    cout<<n<<" "<<endl;
}
void dec(int n)
{
    if(n==1)
    {
        cout<<"1";
        return;
    }
    cout<<n<<" "<<endl;
    dec(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<"print n number in increasing order:"<<endl;
    inc(n);
    cout<<"print n number in decreasing order:"<<endl;
    dec(n);
    return 0;
}
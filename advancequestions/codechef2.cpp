#include <iostream>
using namespace std;

unsigned long long factorial(int a)

{
    if(a==0)
    {
        return 1;
    }
    else{
    int ans=1;
    for(int i=1;i<=a;i++)
    {
        ans=ans*i;
    }
    return ans;
    }
}

int main()

{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<factorial(n)<<endl;
    }
	return 0;
}

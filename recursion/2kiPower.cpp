
#include<iostream>
using namespace std;

int exp(int n)
{
    if(n==0)
    {
        return 1;
    }
    int answer=exp(n/2);

    if(n&1)
    {
        return 2*answer*answer;
    }
    return answer*answer;
}

int main()
{
    int n;cin>>n;
    cout<<exp(n);
    return 0;
}
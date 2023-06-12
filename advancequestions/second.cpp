#include<bits/stdc++.h>
// all function are difining in this header file 
using namespace std;
int main()
{
    int n,reverse=0;
    // input from the user 
    cout<<"enter the number\n";
    cin>>n;

    int rm;
    // revers the all positive number 
    while(n>0)
    {
        // find the last digit of the number 
        rm=n%10;
        reverse=reverse*10+rm;
        n=n/10;
    }
    // finally reverse the gien number is 
    cout<<reverse<<endl;
    return 0;
}
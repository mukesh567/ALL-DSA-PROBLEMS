#include<iostream>
using namespace std;

// positive decimal number from right to left
// this is the main functions 
int main()
{
    // input from the user 
    int n;
    cout<<"enter the value of n\n";
    cin>>n;
// all positive number
while(n>0)
{
    // find the last digit of the number
    int rem=n%10;
    cout<<rem<<endl;
    // define the next remaining number
    n=n/10;
}
    return 0;
}
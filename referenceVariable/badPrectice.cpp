
#include<bits/stdc++.h>
using namespace std;

int & fun(int n)
{
    int num = n;
    int &ans = num;
    return ans;
}

int main()
{
    int n=8;

  cout<< fun(n)<<endl;
    
    return 0;
}
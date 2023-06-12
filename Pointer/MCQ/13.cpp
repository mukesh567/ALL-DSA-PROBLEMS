
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6]={11,21,31,41};

    int *ptr = arr+1;      // not possible arr=arr+1

    cout<<*ptr<<endl;
    
    return 0;
}
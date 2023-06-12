
#include<bits/stdc++.h>
using namespace std;
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void findpermutations(int a[],int n)
{
    sort(a,a+n);
    reverse(a,a+n);
    do{
        display(a,n);
    }while(prev_permutation(a,a+n));
    cout<<" After loop:"<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<endl;
}

int main()
{
    int n;
    cin>>n;
    int a[]={1,2,3};
    findpermutations(a,n);
    return 0;
}
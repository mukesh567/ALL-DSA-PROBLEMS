
#include<bits/stdc++.h>
using namespace std;

void GetPerm(string str,int index)
{
    if(index>=str.length())
    {
        cout<<str<<endl;
        return ;
    }

    for(int i=index;i<str.length();i++)
    {
       swap(str[index],str[i]);
       GetPerm(str,index+1);
      // backtracking condition
       swap(str[index],str[i]);
    }
}

int main()
{
    string str;
    cout<<"Enter the string : ";
    cin>>str;

cout<<"All the Permutation is : "<<endl;
    GetPerm(str,0);
    return 0;
}
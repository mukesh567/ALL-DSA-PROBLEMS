
#include<bits/stdc++.h>
using namespace std;


string reverseSt(string &str){

    string ans = "";

    string temp = "";

    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]=='.')
        {
           reverse(temp.begin(),temp.end());
           ans = ans+temp;
           ans.push_back('.');
           temp = "";
        }
        else
        {
            temp.push_back(str[i]);
        }
    }

    //Last vala chars handle 
    reverse(temp.begin(),temp.end());
    ans = ans+temp;
    
  return ans;
}


int main()
{
   string str = "Hey.I.am.Mukesh";

   cout<<reverseSt(str)<<endl;
    return 0;
}
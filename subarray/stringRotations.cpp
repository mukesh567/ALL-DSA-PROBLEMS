# include <bits/stdc++.h>
using namespace std;
 
/* Function checks if passed strings (str1
   and str2) are rotations of each other */
bool areRotations(string str1, string str2)
{
   /* Check if sizes of two strings are same */
   if (str1.length() != str2.length())
        return false;
 
   string temp = str1 + str1;
  return (temp.find(str2) != string::npos);
}
 
/* Driver program to test areRotations */
int main()
{
   string str1 = "AACD", str2 = "ACDA";
   if (areRotations(str1, str2))
     cout<<"Strings are rotations of each other"<<endl;
   else
      cout<<"Strings are not rotations of each other"<<endl;
   return 0;
}
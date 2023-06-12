#include<bits/stdc++.h>

using namespace std;


int main()
{
    set<int>s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(3);

    cout<<*s.lower_bound(1)<<endl;
    cout<<*s.lower_bound(3)<<endl;
    cout<<*s.upper_bound(1)<<endl;
    cout<<*s.upper_bound(3)<<endl;
   
    return 0;
}
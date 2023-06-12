
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // TC = logn
    map<int, string> s;
    
    // TC = O(1)
   //unordered_map<int ,int> m;

    // insertion first method
    s[1] = "mukesh";
    s[3] = "kumar";
    s[5] = "kir";

    // insertion second method
    // pair<int,string> p1 = make_pair(1,"mukesh");
    // s.insert(p1);

    // insertion third method
    // pair<int,string> p2(1,"mukesh");
    // s.insert(p1);

    // insertion fourth method
    // s.insert({1, "mukesh"});
    // s.insert({3, "kumar"});
    // s.insert({5, "kir"});

    // searching
    // cout << s[1] << endl;
    // cout << s.at(1) << endl;

    // searching for unknown key
    // cout << s[2] << endl;
    // cout << s.at(2) << endl;

    // size
    //cout << s.size() << endl;

    // deletion
    // s.erase(5);
    // cout<<"After deletion size is : "<<s.size()<<endl;

    // present or not
    //cout << "is it present or not:" << s.count(2) << endl;

    // print whole map method 1
    for (auto i : s)
    {
        cout << i.first << " " << i.second << endl;
    }

    // print whole map method 2
    map<int, string>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
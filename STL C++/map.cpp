
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> s;
    // s[1]="mukesh";
    // s[3]="kumar";
    // s[5]="kir";

    s.insert({1, "mukesh"});
    s.insert({3, "kumar"});
    s.insert({5, "kir"});
    cout << "Before erase::" << endl;
    for (auto i : s)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "is it present or not:" << s.count(2) << endl;
    cout << "After erase::" << endl;
    s.erase(5);
    for (auto i : s)
    {
        cout << i.first << " " << i.second << endl;
    }
    auto it=s.find(1);
    for(auto i=it;i!=s.end();i++)
    {
        cout << (*i).first <<  endl;
    }
    return 0;
}
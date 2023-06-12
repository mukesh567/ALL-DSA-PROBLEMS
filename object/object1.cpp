
#include <bits/stdc++.h>
using namespace std;

class student
{

    string name;

public:
    int age;
    bool gander;

    // void setName(string s)
    // {
    //     name = s;
    // }
    // void getName(string s)
    // {
    //     cout<<name<<endl;
    // }
    student()
    {
        cout<<"Default Constructor"<<endl;
    }
    student(string s, int y, int g)
    {
        cout<<"Parameterlised Constructor:"<<endl;
        name = s;
        age = y;
        gander = g;
    }
    student(student &a)
    {
        cout<<"Copy contructor:"<<endl;
        name=a.name;
        age=a.age;
        gander=a.gander;

    }
~student()
{
    cout<<"Destructor Called::"<<endl;
}
    void printInfo()
    {
        cout<<"Name = ";
        cout << name << endl;
        cout<<"Age = ";
        cout << age << endl;
        cout<<"Gander = ";
        cout << gander << endl;
    }
};

int main()
{
    //     student arr[3];
    //     for(int i=0;i<3;i++)
    //     {
    // string s;
    // cout<<"Name= ";
    // cin>>s;
    // arr[i].setName(s)
    //         cout<<"age= ";
    //         cin>>arr[i].age;
    //         cout<<"gander= ";
    //         cin>>arr[i].gander;
    //     }
    // for(int i=0;i<3;i++)
    // {
    //     arr[i].printInfo();
    // }
    student a("mukesh",21,1);
    // a.printInfo();
    // student b;
    student c=a;
     c.printInfo();
    return 0;
}
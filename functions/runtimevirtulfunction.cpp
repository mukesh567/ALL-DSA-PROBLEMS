
#include <bits/stdc++.h>
using namespace std;
class base
{
public:
    virtual void print()
    {
        cout << "this is our base class" << endl;
    }
   virtual void display()
    {
        cout << "this is our display base class" << endl;
    }
};
class derived : public base
{
public:
    void print()
    {
        cout << "this is our derived class" << endl;
    }
    void display()
    {
        cout << "this is our display derived class" << endl;
    }
};

int main()
{
    base *mu;
    derived d;
    mu = &d;
    mu->print();
    mu->display();
    return 0;
}
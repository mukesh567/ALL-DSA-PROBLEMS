
#include<bits/stdc++.h>
using namespace std;
class A{
public:
void muk()
{
    cout<<"Inherited\n"<<endl;
}
};
class B : public A{
    public:
void shiv()
{
    cout<<"my name is shiva\n"<<endl;
}
};
class C : public B{
    public:
};
int main()
{
    // A m;
    // m.muk();
    // B s;
    // s.muk();
    // B k;
    // k.shiv();
    C r;
    r.muk();
    r.shiv();

    return 0;
}
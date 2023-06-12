
#include <bits/stdc++.h>
#define pi 3.14
using namespace std;
class mukesh
{
public:
    void muk()
    {
        cout << "pass no argument" << endl;
    }
    void mukk(int x)
    {
        //area of circle
        int area;
         area=pi * x * x;
         cout<<"area of circle is : "<<area<<endl;
    }
    void mukkk(double x)
    {
        cout << "pass double argument" << endl;
    }
};
int main()
{
    mukesh s;
    s.muk();
    s.mukk(4);
    s.mukkk(3.6);
    return 0;
}
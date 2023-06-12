
#include<bits/stdc++.h>
using namespace std;

class Complex{
private:
int real,img;
public:
 Complex(int r=0,int i=0)
 {
     real=r;
     img=i;
 }
 Complex operator + (Complex const &obj)
 {
     Complex res;
     res.img=img + obj.img;
     res.real=real + obj.real;
     return res;
 }
 void display()
 {
     cout<<real<<" +i"<<img<<endl;
 }
};
int main()
{
    Complex c1(2,5);
    Complex c2(4,5);
    Complex c3=c1+c2;
    c3.display();

    return 0;
}
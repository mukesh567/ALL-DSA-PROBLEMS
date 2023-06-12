
#include<bits/stdc++.h>
using namespace std;
class A
{
    private:

    int b;
    
public:
    int a;
    void set(int a)
    {
        b=a;
    }

   int get()
   {
       return b;
   }

// protected:
//     int c;
//     void funcC()
//     {
//         cout << "Func C\n";
//     }
};
int main()
{
    A obj;
    obj.set(9);
    cout<<obj.get()<<endl;
    // obj.funcB();
}

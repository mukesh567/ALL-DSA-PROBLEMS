
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i = 5;

    int *ptr = &i;

    int **ptr2 = &ptr;

    cout << "Address of i is : " << &i << endl;

    cout << "Address of i is : " << ptr << endl;

    cout << "Address of i is : " << *ptr2 << endl;



    cout << "Address of ptr is : " << &ptr << endl;

    cout << "Address of ptr is : " << ptr2 << endl;




    cout << "Value of i is : " << i << endl;

    cout << "Value of i is : " << *ptr << endl;

    cout << "Value of i is : " << **ptr2 << endl;

    return 0;
}
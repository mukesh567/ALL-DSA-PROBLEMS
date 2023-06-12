
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 7;

    int *p = &num;

    cout << endl;

    cout << "Address of num is : " << p << endl;

    cout << "Value of num is : " << *p << endl;

    // copy pointer
    int *q = p;

    cout << endl;

    cout << "Address of num is : " << q << endl;

    cout << "Value of num is : " << *q << endl;

    cout << endl;

    return 0;
}
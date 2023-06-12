
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 5;

    // create reference variable          ( same memory different name => reference variable)
    int &j = i;

    cout << "i  is : " << i << endl;

    j++;
    cout << "After j increament , i is  : " << i << endl;

    // i++;
    // cout << "After i increament : " << i << endl;

    return 0;
}
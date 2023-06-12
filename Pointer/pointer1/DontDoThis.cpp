
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pointer to int is created ,and pointing to some garbage value
    // Es problem se bachne k liye zero se intialize kar do jiski koi memory exists nhi karti

    int *p;

    cout << "Value is : " << *p << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int num = 5;

    // intialize simple variable
    int a = num;

    cout << endl;

    cout << "variable increament karne par : " << endl;

    cout << "Before increament : " << num << endl;

    ++a;

    cout << "After increment : " << num << endl;

    cout << endl;

    // intialize pointer
    int *ptr = &num;

    cout << "pointer increament karne par : " << endl;

    cout << "Before increament : " << num << endl;

    (*ptr)++;

    cout << "After increament : " << num << endl;

    cout << endl;
    return 0;
}
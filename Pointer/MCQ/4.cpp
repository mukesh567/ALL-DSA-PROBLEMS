
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *ptr = 0;
    int first = 110;
    *ptr = first;   // galti

    cout << *ptr << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int first = 8;

    int *ptr = &first;

    cout << (*ptr)++ << endl;
    cout << first << endl;

    return 0;
}
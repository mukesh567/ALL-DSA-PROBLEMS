
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int first = 8;
    int second = 11;

    int *third = &second;
    *third = *third + 2;

    cout << "First value is : " << first << endl;
    cout << "Second value is : " << second << endl;

    return 0;
}
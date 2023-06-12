
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int first = 8;
    int second = 18;

    int *ptr = &second;
    *ptr = 9;

    cout << "First is : " << first << endl;
    cout << "Second is : " << second << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int first = 6;
    int *p = &first;

    int *q = p;

    (*q)++;

    cout << "First is : " << first << endl;

    return 0;
}
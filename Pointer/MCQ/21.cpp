
#include <bits/stdc++.h>
using namespace std;

void increament(int **p)
{

    ++(**p);
}

int main()
{
    int first = 110;

    int *ptr = &first;

    increament(&ptr);

    cout << first << endl;

    return 0;
}
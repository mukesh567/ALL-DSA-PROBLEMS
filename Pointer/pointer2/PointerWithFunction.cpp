
#include <bits/stdc++.h>
using namespace std;

void printValue(int *m)
{
    cout << "Address of this value is : " << m << endl;
    cout << "Value is : " << *m << endl;
}

int main()
{
    int value = 80;

    int *ptr = &value;

    printValue(ptr);

    return 0;
}
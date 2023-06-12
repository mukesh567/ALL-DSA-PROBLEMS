
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int a = 35;
    int *b;
    b = &a;
    cout << a << endl;
    cout << b << endl;
    cout << *b << endl;
    *b = 57;
    cout << a << endl;
// passing pointer in array  
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *p;
    p = arr;
    for (int i = 0; i < 6; i++)
    {
        cout << *(p + i) << endl;
    }
    return 0;
}

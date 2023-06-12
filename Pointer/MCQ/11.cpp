
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6] = {11, 21, 31};
    int *ptr = arr;

    cout << ptr[2] << endl;    // Same as *(ptr+2)

    return 0;
}
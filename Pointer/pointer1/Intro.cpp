
#include <bits/stdc++.h>
using namespace std;

// ptr or &num is same
// *ptr or num  is same

int main()
{
    int num = 6;

    cout << "The number is : " << num << endl;

    // address of operator  &

    cout << "Address of num is : " << &num << endl;

    // create pointer
    // data type koi bhi ho sakta hai
    int *ptr = &num;

    cout << "Address of num is : " << ptr << endl;

    cout << "The number is : " << *ptr << endl;

    cout << "Size of integer is : " << sizeof(num) << endl;
    cout << "Size of pointer is : " << sizeof(ptr) << endl;
    return 0;
}

//int *ptr=&num  and int *ptr=0,ptr=&num is same

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 6;

    cout << "The number is : " << num << endl;

    // address of operator  &

    cout << "Address of num is : " << &num << endl;

    // create pointer
    // data type koi bhi ho sakta hai
    int *ptr = 0;
    ptr = &num;

    cout << "Address of num is : " << ptr << endl;

    cout << "The number is : " << *ptr << endl;

    cout << "Size of integer is : " << sizeof(num) << endl;
    cout << "Size of pointer is : " << sizeof(ptr) << endl;
    return 0;
}
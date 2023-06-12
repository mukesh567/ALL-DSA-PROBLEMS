
#include <bits/stdc++.h>
using namespace std;

int main()
{
    
//diff 1.  size ka

    int arr[10] = {7, 9};
    cout << "Size of entire array is : " << sizeof(arr) << endl;

    cout << "Size of entire value is : " << sizeof(*arr) << endl;

    cout << "Size of entire array is : " << sizeof(&arr) << endl;


    int *ptr = &arr[0];

    cout << "Size of pointer is : " << sizeof(ptr) << endl;

    cout << "Size of pointer to point value  is : " << sizeof(*ptr) << endl;


    

    //diff 2. & operator ka

        // int a[50] = {2, 3, 4, 5};

        // cout << "Address -> " << &a << endl;

        // int *p = &a[0];
        // cout << "Address -> " << p << endl;

    


//diff 3. simble table


    // int arr[8] = {4, 5};

    // // arr=arr+1    // it is not allowed

    // int *ptr = &arr[0];

    // ptr = ptr + 1;    //shift to one memory block forward

    // cout << ptr << endl;


    return 0;
}
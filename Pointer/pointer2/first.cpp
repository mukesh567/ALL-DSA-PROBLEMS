
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {2, 3, 4, 5};

    cout << "First value is : " << arr[0] << endl;

    cout << "Address of first memory block is : " << arr << endl; 

    cout << "Address of first memory block is : " << &arr[0] << endl;

    cout << "First value is : " << *arr << endl;

    cout << "Increament first value by 1 : " << *arr + 1 << endl;

    cout << "Second value is : " << *(arr + 1) << endl;

    cout << "Increament first value by 1 : " << (*arr) + 1 << endl;

    cout << "Third value of this array is : " << arr[2] << endl;

    cout << "Third value of this array is : " << *(arr + 2) << endl;

    int i = 3;
    cout << "Fourth value of this array is : " << i[arr] << endl;

    

    return 0;
}
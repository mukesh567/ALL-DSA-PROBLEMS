
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int num = 8;

     int *ptr = &num;

     cout << endl
          << "Before increament address : " << ptr << endl;

     ptr = ptr + 1;

     // 4 byte se aage badh jayega purane vaale se
     cout << endl
          << "After increament address : " << ptr << endl;
     cout << endl;
     
     return 0;
}
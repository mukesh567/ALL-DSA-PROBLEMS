
#include <bits/stdc++.h>
using namespace std;

void update(int **ptr2)
{
    // ptr2 = ptr2 + 1;  //(kuch change nhi hoga)

    // *ptr2 = *ptr2 + 1;   // ptr ka address change

    **ptr2=**ptr2+1;      // i change
}

int main()
{
    int i = 5;

    int *ptr = &i;

    int **ptr2 = &ptr;

    cout << endl;

    cout << "Before update : " << i << endl;
    cout << "Before update : " << ptr << endl;
    cout << "Before update : " << ptr2 << endl;
    update(ptr2);
    cout << endl;
    cout << "After update : " << i << endl;
    cout << "After update : " << ptr << endl;
    cout << "After update : " << ptr2 << endl;

    return 0;
}
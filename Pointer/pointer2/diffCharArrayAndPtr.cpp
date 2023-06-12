
#include <bits/stdc++.h>
using namespace std;

int main()

{

    int arr[6] = {1, 2, 3, 4, 5};

    cout << "Print Address of the first block : " << arr << endl;

    char ch[6] = "Rinku";

    cout << "Print whole array : " << ch << endl;

    char *c = &ch[0];

    cout << "Print whole array : " << c << endl;

    // jab tak null character nhi milta print karta jayega m k baad randomly print karega

    // char temp = 'm';

    // char *ptr = &temp;

    // cout << *ptr << endl;

    return 0;
}
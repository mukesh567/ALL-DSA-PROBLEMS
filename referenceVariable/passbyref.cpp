
#include <bits/stdc++.h>
using namespace std;


// Pass by value
// void update(int n)
// {
//    ++n;
// }


// Pass by reference 
void update2(int &n)
{
    ++n;
}

int main()
{
    int n = 5;
    int m = 6;

    cout << "Before n : " << n << endl;

    update2(n);

    cout << "After n : " << n << endl;

    return 0;
}
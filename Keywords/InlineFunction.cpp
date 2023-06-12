
// Inline Function => are used to reduce function calls overhead

#include <bits/stdc++.h>
using namespace std;

// inline function apne aap function call ko replace karega apni condition(function body) se (compile time pe)
inline int getMax(int &a, int &b)
{
    return (a > b) ? a : b;
}
int main()
{
    int a = 2, b = 4;

    int ans = 0;

    ans = getMax(a, b); // ( ans = (a>b)?a:b;)
    cout << ans << endl;

    a += 4;
    b += 1;

    ans = getMax(a, b);
    cout << ans << endl;

    return 0;
}

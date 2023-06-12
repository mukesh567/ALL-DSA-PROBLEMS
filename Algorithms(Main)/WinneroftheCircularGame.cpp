
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
    // Zero base index hai to n==1 means 0
    //% hamesha zero base index ans deta hai
    if (n == 1)
        return 0;

    return (solve(n - 1, k) + k) % n;
}

int findTheWinner(int n, int k)
{
    // 1 base index k liye 1 +
    int ans = solve(n, k) + 1;
    return ans;
}

int main()
{
    // Start at friend 1
    int n = 5; // friends
    int k = 3;

    cout << findTheWinner(n, k) << endl;

    return 0;
}
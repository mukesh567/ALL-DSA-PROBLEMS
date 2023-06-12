
#include <bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k)
{
    // declare dequeue
    deque<int> maxi(k);
    deque<int> mini(k);
    int ans = 0;

    // addition of first k size window

    for (int i = 0; i < k; i++)
    {
        // maxi k liye
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        // mini k liye
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        // push in max and min element index
        maxi.push_back(i);
        mini.push_back(i);
    }

    // firstly store the ans
    ans += arr[maxi.front()] + arr[mini.front()];

    // agli windows k liye
    for (int i = k; i < n; i++)
    {

        // removel first element
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition agla element
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        // push in max and min element index
        maxi.push_back(i);
        mini.push_back(i);

        // lastly store the ans
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    cout << "The sum of maxi and mini subarray of size k is : " << solve(arr, 7, k) << endl;

    return 0;
}
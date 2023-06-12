

#include <bits/stdc++.h>
using namespace std;

vector<int> findNonReN(int *arr, int n)
{
    vector<int> ans;


    int Xor = arr[0];
    for (int i = 1; i < n; i++)
    {
        Xor ^= arr[i];
    }

    int rightMostBit = Xor & ~(Xor - 1);

    // our answer
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rightMostBit)
        {
            x ^= arr[i];
        }
        
        else
        {
            y ^= arr[i];
        }
    }

    ans.push_back(x);
    ans.push_back(y);
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    // two non-repeating n is 3 and 4
    int arr[6] = {1, 2, 3, 2, 1, 4};

    vector<int> ans = findNonReN(arr, 6);
    cout << "Two non-repeating number is : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
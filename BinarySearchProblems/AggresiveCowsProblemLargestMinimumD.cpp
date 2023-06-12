#include <bits/stdc++.h>
using namespace std;

bool isPossible(int stalls[], int n, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < n; i++)
    {

        if (stalls[i] - lastPos >= mid)
        
        {
            cowCount++;

            if (cowCount == k)
            {
                return true;
            }

            lastPos = stalls[i];
        }
    }

    return false;
}

int findLargestDistance(int stalls[], int n, int k)
{

    sort(stalls, stalls + n);

    int start = 0, end, maxi = -1;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, stalls[i]);
    }

    end = maxi;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(stalls, n, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{

    int stalls[5] = {2, 1, 4, 6, 3};
    int k = 2; // cows

    cout << "Largest distance : " << findLargestDistance(stalls, 5, 2) << endl;
    return 0;
}
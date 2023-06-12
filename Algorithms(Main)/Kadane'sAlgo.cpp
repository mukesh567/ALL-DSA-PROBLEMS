
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];

        if (currSum > maxi)
        {
            maxi = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    return maxi;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(nums) << endl;

    return 0;
}
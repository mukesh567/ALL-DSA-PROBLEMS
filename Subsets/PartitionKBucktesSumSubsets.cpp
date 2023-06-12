

#include <bits/stdc++.h>
using namespace std;

bool helper(int i, int bucketNum, int bucketSum, int reqSum, int k,
            vector<int> &arr, vector<int> &alreadyPicked)
{
    // base cases
    if (bucketSum == reqSum)
    {
        // if bucketSum==reqSum then we start from the beggning bucketsum and i will be zero
        // and bucketNum we already have one bucket so jump to new bucket
        return helper(0, bucketNum + 1, 0, reqSum, k, arr, alreadyPicked);
    }

    if (bucketNum == k + 1)
        return true;

    if (bucketSum > reqSum)
        return false;

    if (i >= arr.size())
        return false;

    // if elements are already picked then
    if (alreadyPicked[i] == 1)
    {
        return helper(i + 1, bucketNum, bucketSum, reqSum, k, arr, alreadyPicked);
    }

    // not already picked
    else
    {
        // then pick
        bucketSum += arr[i];
        alreadyPicked[i] = 1;
        bool op1 = helper(i + 1, bucketNum, bucketSum, reqSum, k, arr, alreadyPicked);

        // then skip
        bucketSum -= arr[i];
        alreadyPicked[i] = 0;
        bool op2 = helper(i + 1, bucketNum, bucketSum, reqSum, k, arr, alreadyPicked);

        // return
        return op1 | op2;
    }
}

bool isKPartitionPossible(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> alreadyPicked(n, 0);

    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    if (sum % k != 0)
        return false;

    // har ak bucket me itna sum hona chahiye
    int reqSum = sum / k;

    return helper(0, 1, 0, reqSum, k, arr, alreadyPicked);
}

int main()
{
    // number of bucktes
    // jinke ander subset aayenge jinaka sum equal hoga
    int k = 3;

    vector<int> arr = {2, 1, 4, 5, 6};

    if (isKPartitionPossible(arr, k))
    {
        cout << "we can divide above array 
            into 3 parts with equal sum as(2, 4),
            (1, 5), (6) " << endl;
    }
    else
    {
        cout << "Not possible" << endl;
    }

    return 0;
}
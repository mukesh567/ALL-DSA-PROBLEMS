
#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int> arr, int M)
{

    // sort
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = M - 1;

    int mini = INT_MAX;

    while (j < arr.size())
    {
        int diff = arr[j] - arr[i];
        mini = min(mini, diff);
        i++;
        j++;
    }

    return mini;
}

int main()
{
    // choclete packets
    vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12};

    // number of students
    int M = 5;

    // print the maximum and minimum packets min diff
    cout << findMinDiff(arr, M) << endl;
}
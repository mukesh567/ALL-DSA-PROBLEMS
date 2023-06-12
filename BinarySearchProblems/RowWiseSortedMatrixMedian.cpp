
#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> &matrix, int r, int c)
{

    // constraints ko ranges banane par(1 to 2000)
    // ya ham matrix ka sabse min or max leke bhi range bana sakte hai
    //  search space
    int startVal = 1;
    int endVal = 2000;

    int totalEle = r * c;

    while (startVal <= endVal)
    {
        int midVal = (endVal + startVal) / 2;
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            int low = 0, high = c - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] <= midVal)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            ans += low;
        }
        if (ans <= totalEle / 2)
        {
            startVal = midVal + 1;
        }
        else
        {
            endVal = midVal - 1;
        }
    }
    return startVal;
}

int main()
{
    int r = 3;
    int c = 3;

    vector<vector<int>> matrix{
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};

    cout << "Median in this matrix is : " << findMedian(matrix, r, c) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int minJumps(int *arr, int n)
{
    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    // base case
    if (n == 1)
    {
        return 0;
    }

    else if (arr[0] == 0)
    {
        return -1;
    }
    
    else
    {

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jump;
            }

            // maxreach ko aage badhane par original se
            maxReach = max(maxReach, i + arr[i]);
            step--;

            if (step == 0)
            {
                jump++;

                if (i >= maxReach)
                {
                    return -1;
                }

                step = maxReach - i;
            }
        }
    }
}

int main()
{
    int arr[11] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << endl
         << "Minimum number of jumps to reach end of the array is : " << minJumps(arr, 11) << endl
         << endl;
    return 0;
}
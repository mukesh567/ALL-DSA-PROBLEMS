
#include <bits/stdc++.h>
using namespace std;
bool sorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    int restsorted = sorted(arr + 1, n - 1);
    return (arr[0] < arr[1] && restsorted);
}
int main()
{
    int arr[] = {1, 2, 6, 4, 5};
    int result = sorted(arr, 5);
    cout << result << endl;
    return 0;
}
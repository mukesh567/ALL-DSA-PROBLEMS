
#include <bits/stdc++.h>
using namespace std;

void findTriplet(int arr[], int n, int sum)
{

    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            if (arr[i] + arr[left] + arr[right] == sum)
            {
                cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
                break;
            }

            else if (arr[i] + arr[left] + arr[right] < sum)
            {
                left++;
            }
            
            else
            {
                right--;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum;
    cout << "Enter the sum : ";
    cin >> sum;

    findTriplet(arr, n, sum);
    return 0;
}
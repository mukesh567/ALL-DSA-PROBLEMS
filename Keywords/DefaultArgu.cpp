
#include <bits/stdc++.h>
using namespace std;


// start is the opational   (default argu hamesha right most me hona chahiye)
void print(int *arr, int n, int start=3)
{
    for (int i = start; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    print(arr, 6);

    return 0;
}
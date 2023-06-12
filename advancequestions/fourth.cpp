#include <bits/stdc++.h>
using namespace std;
// program to find min an max number 
int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxno = INT_MIN;
    int minno = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        maxno = max(maxno, arr[i]);
        minno = min(minno, arr[i]);
    }
    cout << "Maxno=" << maxno << endl;
    cout << "minno=" << minno << endl;
    return 0;
}
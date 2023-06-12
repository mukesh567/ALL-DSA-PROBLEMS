
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //As 1 5 7 1    k=6  :  1+5=6,5+1=6, than ans=2;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
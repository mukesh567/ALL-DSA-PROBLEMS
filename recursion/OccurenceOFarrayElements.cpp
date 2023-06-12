
#include <bits/stdc++.h>
using namespace std;
int firstoccu(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return firstoccu(arr, n, i + 1, key);
}
int lastoccu(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restoccu = lastoccu(arr, n, i + 1, key);
    if (restoccu != -1)
    {
        return restoccu;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    cout<<"First occurence of given number is::"<<endl;
    int result = firstoccu(arr, 7, 0, 2);
    cout << result << endl;
    cout<<"Last occurence of given number is::"<<endl;
    int answer = lastoccu(arr, 7, 0, 2);
    cout << answer << endl;
    return 0;
}
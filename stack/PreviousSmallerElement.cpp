
#include <bits/stdc++.h>
using namespace std;

void PreviousSmallerElement(int arr[], int n)
{
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            cout << "-1" <<" ";
        }
        else
        {
            cout << st.top() << " ";
        }
        st.push(arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    PreviousSmallerElement(arr, n);
    return 0;
}
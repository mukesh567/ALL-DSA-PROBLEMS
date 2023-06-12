
#include <bits/stdc++.h>
using namespace std;

void NextGreatestElement(int arr[], int n)
{
    stack<int> st;
    int res[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        // bada element mil chuka hai
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
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
    NextGreatestElement(arr, n);
    return 0;
}
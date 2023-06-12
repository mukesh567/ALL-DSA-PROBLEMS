
#include <bits/stdc++.h>
using namespace std;

void NextSmallerElement(int arr[], int n)
{
    stack<int> st;
    st.push(-1);
    int res[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        // hame top vala chota element mil chuka hai
        res[i] = st.top();
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
    NextSmallerElement(arr, n);
    return 0;
}
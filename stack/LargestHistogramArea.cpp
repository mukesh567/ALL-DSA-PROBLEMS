
#include <bits/stdc++.h>
using namespace std;

vector<int> PreviousSmallerElement(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> prev(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        prev[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return prev;
}
vector<int> NextSmallerElement(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> next(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        next[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return next;
}
int maxArea(vector<int> &arr, int n)
{
    int maxArea = INT_MIN;

    vector<int> prev(n);
    prev = PreviousSmallerElement(arr, n);

    vector<int> next(n);
    next = NextSmallerElement(arr, n);

    // width = next[i] - prev[i] -1

    for (int i = 0; i < n; i++)
    {
        int length = arr[i];

        // kahi next -1 to nhi ho gya
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;

        int newArea = length * breadth;
        maxArea = max(maxArea, newArea);
    }
    return maxArea;
}
int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxArea(arr, n) << endl;
    return 0;
}
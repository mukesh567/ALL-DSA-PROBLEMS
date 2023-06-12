
#include <bits/stdc++.h>
using namespace std;

vector<int> PreviousSmallerElement(int *arr, int n)
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
vector<int> NextSmallerElement(int *arr, int n)
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
int LargestHistogramArea(int *arr, int n)
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

int maxRectangleAreaOfSubMatrix(int arr[][4], int n, int m)
{
    // compute are for first row
    int area = LargestHistogramArea(arr[0], m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row update by adding previous row's value
            if (arr[i][j] != 0)
            {
                arr[i][j] = arr[i][j] + arr[i - 1][j];
            }
            else
            {
                arr[i][j] = 0;
            }
        }
        area = max(area, LargestHistogramArea(arr[i], m));
    }
    return area;
}
int main()
{

   
    int arr[4][4] =
        {
            {0, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
        };

    int maxArea = maxRectangleAreaOfSubMatrix(arr, 4, 4);
    cout << "Largest rectangle area of this binary matrix is  : " << maxArea << endl;
    return 0;
}
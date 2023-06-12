
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> st, int size, int count)
{
    // base case
    if (count == size / 2)
    {
        int ans = st.top();
        cout << "Deleted element is : " << ans << endl;
        return;
    }

    // top element ko side me rakhne par
    int topVal = st.top();
    st.pop();

    // recursive call
    solve(st, size, count + 1);

    // vaapas aate vaqt topVal add karne par
    st.push(topVal);
}
void deleteMiddleEle(stack<int> st, int size)
{
    int count = 0;
    solve(st, size, count);
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    int size = st.size();
    deleteMiddleEle(st, size);

    return 0;
}
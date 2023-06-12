
#include <bits/stdc++.h>
using namespace std;

void insertAtbottom(stack<int> &st, int x)
{
    // base case
    if (st.empty())
    {
        st.push(x);
        return;
    }

    // top element side me rakhne par
    int topVal = st.top();
    st.pop();

    // recursive call
    insertAtbottom(st, x);

    // vaapas add kar do top ko
    st.push(topVal);
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);

    insertAtbottom(st, 5);
    cout << "After insert in bottom : " << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;

    // step-1 all the q elements push on stack
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    // step-2 all the stack elements push on queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // printing the reverse queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;

    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    cout << endl
         << "The reverse queue is : ";
    reverseQueue(q);
    cout << endl;
    return 0;
}
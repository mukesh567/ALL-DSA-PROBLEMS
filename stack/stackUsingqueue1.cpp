#include <bits/stdc++.h>
using namespace std;

class _Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    _Stack()
    {
        N = 0;
    }

    void push(int val)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        q1.pop();
        N--;
    }

    int top()
    {
        return q1.front();
    }
    int size()
    {
        return N;
    }
};

int main()
{
    _Stack st;
    st.push(2);
    st.push(3);
    st.pop();
    st.push(4);
    st.pop();

 
    return 0;
}

// Q 11. Write a program to perform push and pop operation in stack?

#include <bits/stdc++.h>
#define n 100
using namespace std;

class _stack
{

    int top;
    int *arr;

public:
    _stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    _stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
   // cout << st.Top() << endl;
    st.pop();
    cout << st.empty() << endl;

    return 0;
}
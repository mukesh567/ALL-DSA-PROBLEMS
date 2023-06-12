#include <bits/stdc++.h>
using namespace std;
#define n 100

class _stack
{
    int *arr;
    int top;

public:
    _stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow!!" << endl;
            return;
        }

        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop!" << endl;
            return;
        }

        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "No element in stack!" << endl;
            return -1;
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
    cout << "Top element is::" << endl;
    cout << st.Top() << endl;
    st.pop();
    cout << "Top element is::" << endl;
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    cout << st.empty() << endl;

    return 0;
}
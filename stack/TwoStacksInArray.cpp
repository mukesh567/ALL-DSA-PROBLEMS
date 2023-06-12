
#include <bits/stdc++.h>
using namespace std;

class _stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    // constructor
    _stack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // push in stack1
    // left to right
    void push1(int val)
    {
        // if space is availble
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = val;
        }
        else
        {
            cout << "Stack overflow! " << endl;
        }
    }

    // push in stack2
    //  right to left
    void push2(int val)
    {
        // if space is availble
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = val;
        }
        else
        {
            cout << "Stack overflow! " << endl;
        }
    }

    // pop in stack1 and return the popped element
    int pop1()
    {
        // atleast one element present
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // pop in stack2 and return the popped element
    int pop2()
    {
        // atleast one element present
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    _stack st(6);
    st.push1(6);
    st.push1(5);
    st.push1(4);
    st.push1(3);

    cout << st.pop1() << endl;

    st.push2(2);
    st.push2(1);

    cout << st.pop2() << endl;

    return 0;
}
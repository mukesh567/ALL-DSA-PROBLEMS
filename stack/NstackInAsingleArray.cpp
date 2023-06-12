#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;
    // Number of stack
    int n;
    // size of array
    int s;
    // space hai k nhi
    int freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top intilized by -1
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next intilized by agla index
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // next ka last vala -1 hota hai
        next[s - 1] = -1;

        // freeSpot intilized
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freeSpot == -1)
        {
            return false;
        }

        // step-1 find index
        int index = freeSpot;

        // step-2 update freeSpot
        freeSpot = next[index];

        // step-3 insert element
        arr[index] = x;

        // step-3 update next
        next[index] = top[m - 1];

        // step-4 update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow
        if (top[m - 1] == -1)
        {
            return -1;
        }

        // push ka ulta
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main()
{
    // 3 stack and 10 size of array
    NStack st(3, 10);

    st.push(2, 1);
    st.push(4, 1);
    st.push(5, 2);
    st.push(6, 3);
    st.push(8, 2);

    cout << st.pop(1) << endl;
    cout << st.pop(2) << endl;
    cout << st.pop(1) << endl;
    cout << st.pop(2) << endl;
    cout << st.pop(3) << endl;

    cout << st.pop(1) << endl;

    return 0;
}
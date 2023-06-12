
#include <bits/stdc++.h>
#define n 100
using namespace std;

class _queue
{
    int *arr;
    int front;
    int back;

public:
    _queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x)
    {
        if ((front == 0 && back == n - 1) || (back == (front - 1) % (n - 1)))
        {
            cout << "queue overflow!" << endl;
            return;
        }

        // first element to insert
        else if (front == -1)
        {
            front = 0;
            back = 0;
            arr[back] = x;
        }

        // back last me hai or front kahi bich me to back ko starting me lane par
        else if (back == n - 1 && front != 0)
        {
            back = 0;
            arr[back] = x;
        }

        // normal case me
        else
        {
            back++;
            arr[back] = x;
        }
    }

        void pop()
    {
        if (front == -1)
        {
            cout << "No elements in queue!!" << endl;
            return;
        }

        // first element ko pop karne k liye
        arr[front] = -1;
        if (front == back)
        {
            front = back = -1;
        }

        // front agar last me ho to ise starting me lane par
        else if (front == n - 1)
        {
            front = 0;
        }

        // normal case
        else
        {
            front++;
        }
    }
    int peek()
    {
        if (front == -1)
        {
            cout << "No elements in queue!!" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    _queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty() << endl;
    cout << q.peek() << endl;
    return 0;
}
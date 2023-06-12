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
        front = 0;
        back = 0;
    }

    void push(int x)
    {
        if (back == n)
        {
            cout << "queue overflow!" << endl;
            return;
        }

        arr[back] = x;
        back++;
    }

    void pop()
    {

        if (front == back)
        {
            cout << "No elements in queue!!" << endl;
            return;
        }

        arr[front] = -1;
        front++;

        if (front == back)
        {
            front = 0;
            back = 0;
        }
    }

    int peek()
    {
        if (front == back)
        {
            cout << "No elements in queue!!" << endl;
            return -1;
        }

        return arr[front];
    }

    bool empty()
    {

        if (front == back)
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
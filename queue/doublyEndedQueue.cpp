

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

    // front me add karne par elements
    void pushFront(int x)
    {
        if ((front == 0 && back == n - 1) || (front != 0 && back == (front - 1) % (n - 1)))
        {
            cout << "queue overflow!" << endl;
            return;
        }

        // first element to insert
        else if (front == -1)
        {
            front = back = 0;
            arr[front] = x;
        }

        // cyclic nature maintain karne par front ko last me le jayenge
        else if (front == 0 && back != n - 1)
        {
            front = n - 1;
            arr[front] = x;
        }

        // normal case me
        else
        {
            front--;
            arr[front] = x;
        }
    }

    void pushBack(int x)
    {
        if ((front == 0 && back == n - 1) || (front != 0 && back == (front - 1) % (n - 1)))
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
    void popFront()
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

    void popBack()
    {
        if (front == -1)
        {
            cout << "No elements in queue!!" << endl;
            return;
        }

        // first element ko pop karne k liye
        arr[back] = -1;
        if (front == back)
        {
            front = back = -1;
        }

        // back agar starting me ho to ise last me lane par
        else if (back == 0)
        {
            back = n - 1;
        }

        // normal case
        else
        {
            back--;
        }
    }

    // front element
    int getFront()
    {
        if (front == -1)
        {
            cout << "No elements in queue!!" << endl;
            return -1;
        }
        return arr[front];
    }

    // rear element
    int getBack()
    {
        if (front == -1)
        {
            cout << "No elements in queue!!" << endl;
            return -1;
        }
        return arr[back];
    }

    // empty or not
    bool empty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    // full or not
    bool isFull()
    {
        if ((front == 0 && back == n - 1) || (front != 0 && back == (front - 1) % (n - 1)))
        {

            return true;
        }
        return false;
    }
};

int main()
{
    _queue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushFront(3);
    q.pushBack(4);

    cout << q.getFront() << endl;
    q.popFront();
    cout << q.getBack() << endl;
    q.popBack();
    cout << q.getBack() << endl;
    q.popFront();
    cout << q.getFront() << endl;
    q.popFront();
    cout << endl;

    cout << q.empty() << endl;

    return 0;
}
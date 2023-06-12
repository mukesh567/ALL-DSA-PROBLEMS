
#include <bits/stdc++.h>
using namespace std;

class kQueue
{

public:
    int n;
    int k;
    int *front;
    int *rear;
    int *next;
    int *arr;
    int freeSpot;

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        // intialized front and rear with -1
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        // update next with i+1 and last element with -1
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        arr = new int[n];
        freeSpot = 0;
    }

    // push oparation
    void enQueue(int data, int Qn)
    {
        // check overflow condition
        if (freeSpot == -1)
        {
            cout << "No empty space to insert element : " << endl;
            return;
        }

        // step-1 find index
        int index = freeSpot;

        // step-2 update freeSpot
        freeSpot = next[index];

        // check wheather first element to insert
        if (front[Qn - 1] == -1)
        {
            front[Qn - 1] = index;
        }
        else
        {
            // link new element to the prev element
            next[rear[Qn - 1]] = index;
        }

        // update next if space not avialble
        next[index] = -1;

        // update rear
        rear[Qn - 1] = index;

        // insert the element
        arr[index] = data;
    }

    // pop operation
    int deQueue(int Qn)
    {
        // check underflow condition
        if (front[Qn - 1] == -1)
        {
            cout << "Queue is empty : " << endl;
            return -1;
        }

        // step-1 find index to pop
        int index = front[Qn - 1];

        // step-2 front ko aage badhane par
        front[Qn - 1] = next[index];

        // step-3 freespace ko manage karne par ....2 free space is present
        next[index] = freeSpot;

        // setp-4 than first free space is
        freeSpot = index;
        return arr[index];
    }
};

int main()
{
    // 10 is arrays size and 3 is queue
    kQueue q(10, 3);
    q.enQueue(10, 1);
    q.enQueue(15, 1);
    q.enQueue(20, 2);
    q.enQueue(25, 1);

    cout << q.deQueue(1) << endl;
    cout << q.deQueue(2) << endl;
    cout << q.deQueue(1) << endl;
    cout << q.deQueue(1) << endl;

    cout << q.deQueue(1) << endl;

    return 0;
}
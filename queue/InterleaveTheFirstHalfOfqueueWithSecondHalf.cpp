
#include <bits/stdc++.h>
using namespace std;

void firstHalfWithSecondHalf(queue<int> &q)
{
    int n = q.size();

    queue<int> newQueue;
    for (int i = 0; i < n / 2; i++)
    {
        newQueue.push(q.front());
        q.pop();
        // q1 = 11 12 13 14
    }

    for (int i = 0; i < n / 2; i++)
    {
        q.push(newQueue.front());
        newQueue.pop();

        q.push(q.front());
        q.pop();

        // 11 15 12 16 13 17 14 18
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    firstHalfWithSecondHalf(q);

    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
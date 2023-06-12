
#include <bits/stdc++.h>
using namespace std;

void reverseKelements(queue<int> &q, int k)
{
    // step-1 first k elements ko q se stack me dalne par
    // like 1 2 3
    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // step 2  elements put in queue from stack

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        // than entire queue is 4 5 6 3 2 1
    }

    // step-3 jo first elements hai unhe last me le jane par
    int t = q.size() - k;
    while (t--)
    {
        int value = q.front();
        q.pop();
        q.push(value);
        // our answer is ready 3 2 1 4 5 6
    }

    // printing the new queue

    cout << endl
         << "After reversing the k elements queue is : ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl
         << endl;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    int k = 3;

    reverseKelements(q, k);

    return 0;
}
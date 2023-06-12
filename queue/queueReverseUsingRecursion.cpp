
#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int top = q.front();
    q.pop();

    reverse(q);
    q.push(top);
}

int main()
{
    queue<int> q;

    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    reverse(q);

    cout << endl
         << "The reverse queue is : ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << endl;
    return 0;
}
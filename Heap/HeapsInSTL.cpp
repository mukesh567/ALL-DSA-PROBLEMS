
#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(9);
    pq.push(5);
    pq.push(8);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(2);
    pqm.push(9);
    pqm.push(5);
    pqm.push(8);
    cout << pqm.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    return 0;
}
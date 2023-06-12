
#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x)
{
    if (pqmax.empty() || pqmax.top() >= x)
    {
        pqmax.push(x);
    }
    else
    {
        pqmin.push(x);
    }
    if (pqmax.size() > pqmin.size())
    {
        int temp = pqmax.top();
        pqmax.pop();
        pqmin.push(temp);
    }
    else if (pqmax.size() < pqmin.size())
    {
        int temp = pqmin.top();
        pqmin.pop();
        pqmax.push(temp);
    }
}
double findMedian()
{
    if (pqmin.size() == pqmax.size())
    {
        return (pqmin.top() + pqmax.top()) / 2.0;
    }

    return pqmax.top();
}
int main()
{

    insert(3);
    cout << findMedian() << endl;
    insert(1);
    cout << findMedian() << endl;
    insert(5);
    cout << findMedian() << endl;
    insert(4);
    cout << findMedian() << endl;
    return 0;
}
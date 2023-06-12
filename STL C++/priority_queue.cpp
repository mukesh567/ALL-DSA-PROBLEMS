
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max_heap
    priority_queue<int> maxi;
    //   mini_heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(5);
    maxi.push(7);

    cout << "Size of queue is : " << maxi.size() << endl;
    int n = maxi.size();
    cout<<"Maxi queue is : ";
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
    cout<<"Empty or not : "<<maxi.empty()<<endl;
    mini.push(1);
    mini.push(3);
    mini.push(5);
    mini.push(7);
    int m = mini.size();
    cout<<"Mini queue is : ";
    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }cout<<endl;
    cout<<"Empty or not : "<<mini.empty()<<endl;
    return 0;
}
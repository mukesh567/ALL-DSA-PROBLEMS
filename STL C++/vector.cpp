#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // initialize vector
    vector<int> m;
    // other method to initialize vector
    vector<int> a(5,8);
    cout<<"Print vector is:: ";
    for(auto i:a){
    cout<<i<<" ";
    }
    cout<<endl;
    // copy vector elements to other vector
    vector <int> s(a);
    cout<<"Print vector is:: ";
    for(auto i:s){
    cout<<i<<" ";
    }
    cout<<endl;
    cout << "Capacity:" << m.capacity() << endl;
    m.push_back(1);
    cout << "Capacity:" << m.capacity() << endl;
    m.push_back(2);
    cout << "Capacity:" << m.capacity() << endl;
    m.push_back(3);
    cout << "Capacity:" << m.capacity() << endl;
    m.push_back(4);
    cout << "Capacity:" << m.capacity() << endl;
    m.push_back(5);
    cout << "Capacity:" << m.capacity() << endl;
    cout << "Size = " << m.size() << endl;
    cout << "second index element is::" << m.at(2) << endl;
    cout << "first element is::" << m.front() << endl;
    cout << "Last element is::" << m.back() << endl;

    cout << "Before pop::" << endl;
    for (auto i : m)
    {
        cout << i << " ";
    }
    cout << endl;
    m.pop_back();
    cout << "After pop::" << endl;
    for (auto i : m)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Before the clear vector size is::" << m.size() << endl;
    m.clear();
    cout << "After the clear vector size is::" << m.size() << endl;
    return 0;
}

#include<iostream>
#include<array>
using namespace std;

int main()
{
    array<int,5> m = {1,2,3,4,5};
    int size = m.size();
    for(int i=0;i<size;i++)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;
    cout<<"second index element is::"<<m.at(2)<<endl;
    cout<<"array empty or not::"<<m.empty()<<endl;
    cout<<"first element is::"<<m.front()<<endl;
    cout<<"Last element is::"<<m.back()<<endl;
    return 0;
}
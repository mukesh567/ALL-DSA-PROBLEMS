
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> s;
    s.push("Mukesh");
    s.push("Kumar");
    s.push("Kir");
    cout << "Size before pop : " << s.size() << endl;
    cout << "First element is : " << s.front() << endl;
    s.pop();
    cout << "First element is : " << s.front() << endl;

    cout << "Size after pop : " << s.size() << endl;
    return 0;
}
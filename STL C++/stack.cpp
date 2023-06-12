
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("KIR");
    s.push("KUMAR");
    s.push("MUKESH");
    cout << "Stack size of ::" << s.size() << endl;
    cout << "Top element is :: " << s.top() << endl;
    s.pop();
    cout << "Top element is :: " << s.top() << endl;
    cout << "Stack Empty or not :: " << s.empty() << endl;
    return 0;
}
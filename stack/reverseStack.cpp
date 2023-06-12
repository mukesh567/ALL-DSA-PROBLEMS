#include <stack>
#include <iostream>
using namespace std;
void insertAtbottom(stack<int> &st, int ele)
{
    // base case
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    // top element uthane par
    int topele = st.top();
    st.pop();

    // recursive call marne par
    insertAtbottom(st, ele);

    // vaapas top ko dalne par
    st.push(topele);
}
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    
    int ele = st.top();
    st.pop();

    reverse(st);
    insertAtbottom(st, ele);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverse(st);
    cout << "After the reverse stack : " endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl;
    return 0;
}
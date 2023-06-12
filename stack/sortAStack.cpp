

#include <iostream>
#include <stack>
using namespace std;
void sortedInsert(stack<int> &st, int ele)
{
    // base case
    if (st.empty() || (!st.empty() && st.top() < ele))
    {
        st.push(ele);
        return;
    }

    // top element
    int topVal = st.top();
    st.pop();

    // recursive call
    sortedInsert(st, ele);

    // vaapas jate samay top ko add karne par
    st.push(topVal);
}
void sortStack(stack<int> &st)
{
    //  base case
    if (st.empty())
    {
        return;
    }

    // top element uthane par
    int topVal = st.top();
    st.pop();

    // recursive call
    sortStack(st);

    // vaapas jate samay sabhi elemnts ko sorted way me insert karne par
    sortedInsert(st, topVal);
}
int main()
{
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(4);
    st.push(-7);
    st.push(2);

    sortStack(st);

    cout << "After sorting the stack : " << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
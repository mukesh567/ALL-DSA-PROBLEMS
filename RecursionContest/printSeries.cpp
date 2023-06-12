
// You have given two positive integers N and K. Your task is to print a series of numbers i.e subtract K from N until it becomes 0 or negative then add K until it becomes N. You need to do this task without using any loop.
// For Example:
// For  N = 5 , K = 2
// Series = [ 5, 3, 1, -1, 1, 3, 5]

#include <bits/stdc++.h>
using namespace std;

void series(int n, int k, vector<int> &answer)
{

    // Add n to answer
    answer.push_back(n);

    // If n<=0 then break the recursion
    if (n <= 0)
    {
        return;
    }

    // Recur for series(answer, n, n-k).
    series(n - k, k, answer);

    // Add n to answer.
    answer.push_back(n);
}

vector<int> printSeries(int n, int k)
{

    vector<int> answer;

    // Call the series function
    series(n, k, answer);

    // Return the answer
    return answer;
}

int main()
{
    int N = 5;
    int K = 2;

    vector<int> ans = printSeries(N, K);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
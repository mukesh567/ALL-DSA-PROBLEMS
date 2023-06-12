
#include <bits/stdc++.h>
// #include<vector>
// #include<numeric>
using namespace std;

int main()
{
    vector<int> s;

    s.push_back(5);

    s.push_back(3);
    
    s.push_back(6);
    // sum of a vector
    cout << "Sum of the vector element is::" << endl;

    int sum = 0;

    sum = accumulate(s.begin(), s.end(), 0);

    cout << sum << " " << endl;

    //    sort of a vector
    cout << "Sorting element is::" << endl;

    sort(s.begin(), s.end());

    for (auto element : s)
    {
        cout << element << " ";
    }
    cout << endl;
    // find the maximum or minimum element of the
    int max = *max_element(s.begin(), s.end());

    int min = *min_element(s.begin(), s.end());

    cout << "Maximum element is::" << endl;

    cout << max << " " << endl;

    cout << "Minimum element is::" << endl;

    cout << min << " " << endl;

    cout << "prefix sum is::" << endl;

    partial_sum(s.begin(), s.end(), s.begin());

    vector<int>::iterator m;

    for (m = s.begin(); m != s.end(); m++)
    {
        cout << *m << " ";
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> v)
{
    int start = 0;
    int end = v.size() - 1;

    while (start < end)
    {
        swap(v[start++], v[end--]);
    }
    return v;
}

vector<int> AddArrays(vector<int> &v1, int n, vector<int> &v2, int m)
{
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    vector<int> ans;

    // agar dono arrays same ho or carry almost na ho
    while (i >= 0 && j >= 0)
    {
        int sum = v1[i] + v2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    // pahla array agar bada ho
    while (i >= 0)
    {
        int sum = v1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    // dusra array agar bada ho
    while (j >= 0)
    {
        int sum = v2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // dono arrays same ho or last me ak carry buch jaye
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    return reverse(ans);
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    int n = v1.size();
    vector<int> v2 = {7, 8};
    int m = v2.size();

    vector<int> ans = AddArrays(v1, n, v2, m);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
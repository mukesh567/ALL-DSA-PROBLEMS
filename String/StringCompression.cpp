
// a b b b c c c d d t(input)
// a b 3 c 3 d 2 t(output length=8)

#include <bits/stdc++.h>
using namespace std;
int compress(vector<char> &str)
{
    int ansIndex = 0;
    int n = str.size();

    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n && str[i] == str[j])
        {
            j++;
        }
        // old character store karne par
        str[ansIndex++] = str[i];

        int count = j - i;

        if (count > 1)
        {
            // converting counting into single digit and saving the answer
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                str[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    vector<char> str = {'a', 'b', 'b', 'b', 'c', 'c', 'c', 'd', 'd', 't'};

    cout << "Length of new string is : " << compress(str) << endl;

    return 0;
}
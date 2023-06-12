
#include <bits/stdc++.h>
using namespace std;

bool AnagramOrNot(string str1, string str2)
{
    // step-1 first we find their size
    int size1 = str1.length();
    int size2 = str2.length();

    // step-2 than compare their size
    if (size1 != size2)
    {
        return false;
    }

    // step-3 than sort the both string
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // step-4 than compare their all char
    for (int i = 0; i < size1; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }

    // step-5 return the answer;
    return true;
}

int main()
{
    string str1 = "mukesh";
    string str2 = "keshmu";

    if (AnagramOrNot(str1, str2))
    {
        cout << "Both are anagram each other (same char,same size) !  " << endl
             << endl;
    }
    else
    {
        cout << "Both are different !" << endl
             << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool checkEqual(int a1[26], int a2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a1[i] != a2[i])
        {
            return 0;
        }
    }
    return 1;
}

bool permutationPresentInOtherString(string s1, string s2)
{
    // first array k characters ka count stores

    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // traverse s2 string in window size of s1 string and compare

    // running for first window

    int winSize = s1.length();
    int count2[26] = {0};
    int i = 0;

    while (i < winSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    // check count1 or count2 kahi equl to nhi

    if (checkEqual(count1, count2))
    {
        return 1;
    }

    // aage ki windows k liye

    while (i < s2.length())
    {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        // first char ko hatana hai

        char oldChar = s2[i - winSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;

        if (checkEqual(count1, count2))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    string s1 = "ab";
    string s2 = "eidaOOO";

    if (permutationPresentInOtherString(s1, s2))
    {
        cout << "True ! s1 ka koi bhi permutation present hai s2 me !" << endl;
    }
    else
    {
        cout << "False ! s1 ka koi bhi permutation present nhi hai s2 me !" << endl;
    }
    return 0;
}
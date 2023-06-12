

#include <bits/stdc++.h>
using namespace std;

// create a class
class TrieNode
{

public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    // create constructer
    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    // constructer
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption, word will  be in small
        int index = word[0] - 'a';
        TrieNode *child;

        // char pehle se present hai
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }

        // char is not present then create the node and insert
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion call
        insertUtil(child, word.substr(1));
    }

    // function for insert word
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // function for LCP
    void lcp(string first, string &ans)
    {
        // traverse first string
        for (int i = 0; i < first.size(); i++)
        {
            char ch = first[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // aage badh jao
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

string commonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    // all the strings insert in trie
    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}

int main()
{
    vector<string> arr = {"coding", "codezen", "codingninja", "coders"};
    int n = arr.size();

    string ans = commonPrefix(arr, n);

    cout << endl
         << endl
         << "The longest common prefix is : " << ans << endl
         << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// create a class
class TrieNode
{

public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // create constructer
    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

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

        // assumption, word will  be in caps
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

    // print all suggestions we have
    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    // get suggestions
    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastCh = str[i];

            prefix.push_back(lastCh);

            // check for lastchar
            TrieNode *curr = prev->children[lastCh - 'a'];

            // if not found
            if (curr == NULL)
            {
                break;
            }

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie('\0');

    // all contact list string insert in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];

        t->insertWord(str);
    }

    return t->getSuggestions(queryStr);
}

int main()
{
    vector<string> contactList = {"cod", "coding", "codding", "code", "coly"};
    string queryStr = "coding";

    vector<vector<string>> ans = phoneDirectory(contactList, queryStr);

    for (int i = 0; i < queryStr.size(); i++)
    {
        for (auto i : ans[i])
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
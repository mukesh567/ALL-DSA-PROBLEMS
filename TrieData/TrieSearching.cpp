

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
    Trie()
    {
        root = new TrieNode('\0');
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
        int index = word[0] - 'A';
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

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // not present
        else
        {
            return false;
        }

        // recursion call for remainning string
        return searchUtil(child, word.substr(1));
    }

    // function for searching word
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("MUKESH");
    t->insertWord("SHIVA");
    t->insertWord("HARISH");

    // searching a string
    if (t->searchWord("MUKESH"))
    {
        cout << "String is present !" << endl;
    }
    else
    {
        cout << "String is not present !" << endl;
    }

    return 0;
}
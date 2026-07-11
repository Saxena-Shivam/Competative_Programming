#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26] = {nullptr};
    bool flag = false;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
    ~Node()
    {
        for (int i = 0; i < 26; i++)
        {
            if (links[i] != nullptr)
            {
                delete links[i];
                links[i] = nullptr;
            }
        }
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    ~Trie()
    {
        delete root;
    }
    void insert(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool search(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};

int main()
{
    Trie *trie = new Trie();
    vector<string> operations = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<vector<string>> arguments = {{}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"}};

    vector<string> output;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "Trie")
        {
            output.push_back("null");
        }
        else if (operations[i] == "insert")
        {
            trie->insert(arguments[i][0]);
            output.push_back("null");
        }
        else if (operations[i] == "search")
        {
            bool result = trie->search(arguments[i][0]);
            output.push_back(result ? "true" : "false");
        }
        else if (operations[i] == "startsWith")
        {
            bool result = trie->startsWith(arguments[i][0]);
            output.push_back(result ? "true" : "false");
        }
    }

    for (string res : output)
    {
        cout << res << endl;
    }

    delete trie;
    return 0;
}
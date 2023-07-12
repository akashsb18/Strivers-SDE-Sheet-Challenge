/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node
{
    Node *links[26];
    bool end = false;
    void put(char ch)
    {
        Node *node = new Node();
        links[ch - 'a'] = node;
    }
    bool contains(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        end = true;
    }
    bool isEnd()
    {
        return end;
    }
};

class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *cur = root;
        for (auto ch : word)
        {
            if (!cur->contains(ch))
            {
                cur->put(ch);
            }
            cur = cur->get(ch);
        }
        cur->setEnd();
    }
    bool searchUtil(string word, bool fullSearch)
    {
        Node *cur = root;
        for (auto ch : word)
        {
            if (!cur->contains(ch))
                return false;
            cur = cur->get(ch);
        }
        return (fullSearch ? cur->isEnd() : true);
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return searchUtil(word, true);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return searchUtil(prefix, false);
    }
};
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Node {

public:
    unordered_map<char, Node*> mapper;
    bool tail = false;
};
class Trie {
public:
    Node *root;
    int cnt = 0;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *p = root;
        for (int i = 0; i < word.size(); i ++) {
            Node* tmp = p->mapper[word[i]];
            if (tmp == nullptr) {
                tmp = new Node();
                p->mapper[word[i]] = tmp;
            }
            p = tmp;
        }
        p->tail = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        cnt ++;
        Node *p = root;
        for (int i = 0; i < word.size(); i ++) {
            Node *tmp = p->mapper[word[i]];
            if (tmp == nullptr) return false;
            p = tmp;
        }
        return p->tail;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *p = root;
        for (int i = 0; i < prefix.size(); i ++) {
            Node *tmp = p->mapper[prefix[i]];
            if (tmp == nullptr) return false;
            p = tmp;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


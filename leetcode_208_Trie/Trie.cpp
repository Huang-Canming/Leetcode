#include <iostream>
#include <string>
#include <vector>

using namespace std;

class trieNode {
private:
    bool isEnd;
    vector<trieNode *> next;
    friend class Trie;
public:
    trieNode() : isEnd(false), next(26, nullptr) {}
};

class Trie {
private:
    trieNode *root;
public:
    Trie() {
        root  = new trieNode();
        return;
    }

    ~Trie() {
        delete root;
        return;
    }
    
    void insert(string word) {
        trieNode *node = root;          // 从根节点开始
        for (char c : word) {
            int index = c - 'a';
            if (nullptr == node->next[index]) {
                node->next[index] = new trieNode();
            }
            node = node->next[index];   // 指向子节点
        }
        node->isEnd = true;             // 指向最后一个字符对应的节点
        return;
    }
    
    bool search(string word) {
        trieNode *node = root;          // 从根节点开始
        for (char c : word) {
            int index = c - 'a';
            if (nullptr == node->next[index]) {
                return false;
            }
            node = node->next[index];
        }
        if (false == node->isEnd) {
            return false;
        } else {
            return true;
        }
    }
    
    bool startsWith(string prefix) {
        trieNode *node = root;          // 从根节点开始
        for (char c : prefix) {
            int index = c - 'a';
            if (nullptr == node->next[index]) {
                return false;
            }
            node = node->next[index];
        }
        return true;
    }
};

int main () {
    Trie* obj = new Trie();
    obj->insert("word");
    bool param_1 = obj->search("word");
    cout << param_1 << endl;
    bool param_2 = obj->search("prefixTest");
    cout << param_2 << endl;
    bool param_3 = obj->startsWith("prefix");
    cout << param_3 << endl;
    return 0;
}
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUNode {
    friend class LRUList;
private:
    int key = -1;
    int val = -1;
    LRUNode *prev = nullptr;
    LRUNode *next = nullptr;
public:
    LRUNode(int key, int val): key(key), val(val) {}
    LRUNode(): prev(nullptr), next(nullptr) {}

    int nodeGetKey()
    {
        return this->key;
    }

    int nodeGetVal()
    {
        return this->val;
    }

    void nodeSetVal(int newVal)
    {
        this->val = newVal;
        return;
    }
};

class LRUList {
private:
    int listNodeNum = 0;
    LRUNode listHead;                   // 头节点，不存放数据内容
public:
    LRUList(): listHead(){}

    int listGetNodeNum(){
        return listNodeNum;
    }

    void listDelNode(LRUNode *node)
    {
        this->listNodeNum--;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return;
    }

    LRUNode *listDelTail()
    {
        LRUNode *listTail = listHead.prev;
        listDelNode(listTail);
        return listTail;
    }

    void listAddHead(LRUNode *node)
    {
        this->listNodeNum++;

        /* 首次加入节点 */
        if (nullptr == this->listHead.next && nullptr == this->listHead.prev)
        {
            this->listHead.prev = node;
            this->listHead.next = node;
            node->prev = &listHead;
            node->next = &listHead;
            return;
        }

        node->prev = &(this->listHead);
        node->next = this->listHead.next;
        node->prev->next = node;
        node->next->prev = node;
        return;
    }

    void listMoveToHead(LRUNode *node)
    {
        listDelNode(node);
        listAddHead(node);
        return;
    }
};

class LRUCache {
private:
    int capacity = 0;
    LRUList nodeList;
    unordered_map<int, LRUNode *> nodeHash;
    
public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        auto iter = nodeHash.find(key);
        if (iter != nodeHash.end())
        {
            int res = iter->second->nodeGetVal();
            nodeList.listMoveToHead(iter->second);
            return res;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto iter = nodeHash.find(key);
        if (iter == nodeHash.end())
        {
            if (nodeList.listGetNodeNum() >= capacity)
            {
                LRUNode *tailNode = nodeList.listDelTail();
                nodeHash.erase(tailNode->nodeGetKey());
                delete(tailNode);
            }

            LRUNode *newNode = new LRUNode(key, value);
            nodeList.listAddHead(newNode);
            nodeHash.insert(pair<int, LRUNode *>(key, newNode));
        }
        else
        {
            iter->second->nodeSetVal(value);
            nodeList.listMoveToHead(iter->second);
        }

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);                 // 缓存是 {1=1}
    lRUCache.put(2, 2);                 // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // 返回 1
    lRUCache.put(3, 3);                 // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // 返回 -1 (未找到)
    lRUCache.put(4, 4);                 // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache.get(3) << endl;    // 返回 3
    cout << lRUCache.get(4) << endl;    // 返回 4

    return 0;
}
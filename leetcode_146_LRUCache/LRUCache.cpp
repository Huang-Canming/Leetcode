#include <iostream>
#include <map>

using namespace std;

class cacheNode{
public:
    int nodeVal = 0;
    unsigned int nodeIndex = 0;

    cacheNode(){
        return;
    }

    cacheNode(int val, unsigned int index){
        nodeVal = val;
        nodeIndex = index;
        return;
    }
};

class LRUCache{
private:
    int cacheCapacity = 0;
    unsigned int nodeIndex = 0;
    map<int, cacheNode> myCache;

public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
        return;
    }
    
    int get(int key) {
        int res = -1;
        auto iter = myCache.find(key);
        if (iter != myCache.end())
        {
            res = iter->second.nodeVal;
            nodeIndex++;
            iter->second.nodeIndex = nodeIndex;
            return res;
        }

        return res;
    }
    
    void put(int key, int value) {

        if (cacheCapacity == (int)myCache.size())
        {
            unsigned int minNodeIndex = myCache.begin()->second.nodeIndex;
            auto iterLRUNode = myCache.begin();
            for (auto iter = myCache.begin(); iter != myCache.end(); iter++)
            {
                if (iter->second.nodeIndex < minNodeIndex)
                {
                    minNodeIndex = iter->second.nodeIndex;
                    iterLRUNode = iter;
                }
            }

            myCache.erase(iterLRUNode);
        }

        nodeIndex++;
        cacheNode node(value, nodeIndex);
        myCache[key] = node;
        return;
    }
};

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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// key:string
// val:int
// val = find(key)
// insert(key, val)

class node {
    string key;
    int val;
    node *next;
    node(string key, int val) : key(key), val(val), next(nullptr) {}
};

class hash {
private:
    int bucketNum;
    vector<node *> buckets;

    int getKeySum (string key) {
        int keySum = 0;
        for (char c : key) {
            keySum += (int)c;
        }
        return keySum;
    }

public:
    hash (int num) : bucketNum(num), buckets(vector<node *>(num, nullptr)) {}

    void insert (string key, int val) {
        int keySum = getKeySum(key);
        int index = keySum % bucketNum;
        node *newNode = new node(key, val);
        if (nullptr == buckets[index]) {
            buckets[index] = newNode;           // a
        } else {
            // 插入到链表头
            newNode->next = buckets[index];     // a -> b -> a
            buckets[index] = newNode;
        }
        return;
    }

    int find (string key) {
        int keySum = getKeySum(key);
        node *nodePtr = buckets[index];
        while (nullptr != nodePtr) {
            if (nodePtr->key == key) {
                break;
            }
            nodePtr = nodePtr->next;
        }
        if (nullptr == nodePtr) {
            return -1;  // 返回一个非法值
        } else {
            return nodePtr->val;
        }
    }
}


// string ( sum(ascii) ) -> int -> % bucket_num

// 线性探测 ：一个 bucket 只有一个 node
//              bucket 1 2 3 4, 5 6

// 拉链法   ：find -> 遍历 bucket 的链表
//              bucket 1, node 1 2 3 4


// 线程内 协程 串行执行的，免锁
// 切换的开销：线程栈、寄存器 
// 调度：业务可控

// 执行时间短：


// 内存池：零拷贝内存，IO 路径（申请），mquota（可申请）

// mutex：切换到其他线程继续执行（睡眠、阻塞），触发系统调用，不断地 lock 和 unlock，纳秒级
// spin_lock：自旋等待，直到拿到锁 -> 锁范围内，执行语句简单，执行速度快
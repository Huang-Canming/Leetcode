#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct numNode {
    int num;
    int index;
    numNode(int num, int index) : num(num), index(index) {}
};

struct numCmp {
    bool operator () (numNode *node1, numNode *node2)
    {
        return node1->num < node2->num;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int numsCnt = nums.size();
        numNode *maxNumNode = nullptr;

        // 构造包含 K 个元素的大顶堆
        priority_queue<numNode*, vector<numNode *>, numCmp> maxHeap;
        for (int i = 0; i < k && i < numsCnt; i++) {
            numNode *rightNode = new numNode(nums[i], i);
            maxHeap.push(rightNode);
        }
        // 最初始的 K 个元素中的最大值
        maxNumNode = maxHeap.top();
        res.push_back(maxNumNode->num);

        // 移动滑动窗口
        for (int left = 1; left + k - 1 < numsCnt; left++) {
            // 新进入窗口的元素补堆
            numNode *rightNode = new numNode(nums[left + k - 1], left + k - 1);
            maxHeap.push(rightNode);
            // 如果大顶堆的堆顶元素已经在滑动窗口范围以外，则弹出堆顶
            maxNumNode = maxHeap.top();
            while (maxNumNode->index < left) {
                maxHeap.pop();
                delete(maxNumNode);
                maxNumNode = maxHeap.top();
            }
            // 找到窗口范围内的最大值
            res.push_back(maxNumNode->num);
        }

        // 销毁剩余节点
        while (!maxHeap.empty()) {
            maxNumNode = maxHeap.top();
            maxHeap.pop();
            delete(maxNumNode);
        }

        return res;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res = solu.maxSlidingWindow(nums, 3);
    for (int maxNum : res) {
        cout << maxNum << endl;
    }
    return 0;
}
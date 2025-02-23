#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
private:
    // 大顶堆放所有数中较小的一半
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // 小顶堆放所有数中较大的一半
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
        return;
    }
    
    void addNum(int num) {
        // 对于个数是奇数的场景，中位数是小顶堆的 top
        // 对于个数是偶数的场景，中位数是大小顶堆 top 的平均值
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            // 偶数场景，maxHeap.size() == minHeap.size() + 2
            // 恢复成 maxHeap.size() == minHeap.size()
            int tmp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(tmp);
        } else if (maxHeap.size() < minHeap.size()) {
            // 奇数场景，maxHeap.size() + 1 == minHeap.size()
            // 恢复成 maxHeap.size() == minHeap.size() + 1
            int tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            double res = 0;
            res = ((double)maxHeap.top() + (double)minHeap.top()) / (double)2;
            return res;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    double median = 0;
    MedianFinder medianFinder;
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    median = medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
    cout << median << endl;
    medianFinder.addNum(3);    // arr[1, 2, 3]
    median = medianFinder.findMedian(); // return 2.0
    cout << median << endl;
    return 0;
}
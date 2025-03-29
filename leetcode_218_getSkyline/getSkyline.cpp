#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#if 0
// not enough memory
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 存储每个横向单位的最大高度（根据“最右侧建筑的右边界”申请空间）
        int heightsSize = buildings[buildings.size() - 1][1];
        vector<int> heights(heightsSize, 0);
        
        // 遍历 buildings 确认每个横向单位的最大高度
        for (vector<int> building : buildings) {
            int left = building[0];
            int right = building[1];
            int height = building[2];
            // heights[i] 存储的是从 heights[i] 到 heights[i+1] 的高度
            for (double i = left; i < right; i++) {
                heights[i] = max(heights[i], height);
            }
        }

        // 生成天际线结果
        vector<vector<int>> skyLine;
        for (int i = 0; i < heightsSize; i++) {
            if (0 == i) {
                if (heights[i] > 0) {
                    skyLine.push_back(vector<int>{i, heights[i]});
                }
            } else {
                if (heights[i] != heights[i - 1]) {
                    skyLine.push_back(vector<int>{i, heights[i]});
                }
            }
        }
        skyLine.push_back(vector<int>{buildings[buildings.size() - 1][1], 0});
        return skyLine;
    }
};
#else
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int left = 0, right = 0, height = 0, xPos = 0;
        int buildCnt = buildings.size();
        vector<int> edges;
        vector<vector<int>> res;                // x pos, height
        priority_queue<pair<int, int>> maxHeap; // height & right

        // 生成扫描线端点
        edges.reserve(buildCnt * 2);
        for (vector<int> build : buildings) {
            left = build[0];
            edges.push_back(left);
            right = build[1];
            edges.push_back(right);
        }
        sort(edges.begin(), edges.end());

        // 遍历扫描线端点
        int i = 0, j = 0;
        int lastHeight = 0, nowHeight = 0;
        for (; i < buildCnt * 2; i++) {
            xPos = edges[i];
            // 建筑物左边界在扫描线左侧的 build 加入大顶堆
            for (; j < buildCnt; j++) {
                left = buildings[j][0];
                if (left <= xPos) {
                    right = buildings[j][1];
                    height = buildings[j][2];
                    maxHeap.emplace(height, right);
                } else {
                    break;
                }
            }

            // 如果堆顶 build 的右边界也在扫描线左侧，把堆顶的 build 弹出
            while (!maxHeap.empty() && maxHeap.top().second <= xPos){
                maxHeap.pop();
            }

            // 把和前一个高度点不同的扫描点加入结果集
            if (maxHeap.empty()) {
                nowHeight = 0;
            } else {
                nowHeight = maxHeap.top().first;
            }

            if (res.empty()) {
                res.push_back({xPos, nowHeight});
            } else {
                lastHeight = res.back()[1];
                if (lastHeight != nowHeight) {
                    res.push_back({xPos, nowHeight});
                }
            }
        }

        return res;
    }
};
#endif

int main() {
    Solution solu;
    vector<vector<int>> buildings1 = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> skyLines1 = solu.getSkyline(buildings1);
    cout << "skyLines:";
    for (vector<int> skyLine : skyLines1) {
        cout << " [" << skyLine[0] << ", " << skyLine[1] << "]";
    }
    cout << endl;

    vector<vector<int>> buildings2 = {{1,2,1},{1,2,2},{1,2,3}};
    vector<vector<int>> skyLines2 = solu.getSkyline(buildings2);
    cout << "skyLines:";
    for (vector<int> skyLine : skyLines2) {
        cout << " [" << skyLine[0] << ", " << skyLine[1] << "]";
    }
    cout << endl;

    return 0;
}
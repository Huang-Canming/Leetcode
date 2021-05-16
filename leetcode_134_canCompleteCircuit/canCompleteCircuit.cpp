#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int vecSize = (int)gas.size(), startPos = 0, nowPos = 0, nextPos = 0, gasLeft = 0;
        vector<int> diff(vecSize, 0);

        if (1 == vecSize && gas[0] >= cost[0]) {
            return 0;
        } else if (1 == vecSize && gas[0] < cost[0]) {
            return -1;
        }

        for (int i = 0; i < vecSize; i++) {
            diff[i] = gas[i] - cost[i];
        }

        for (int i = 0; i < vecSize; i++) {
            if ((0 == i && diff[vecSize - 1] < 0 && diff[0] >= 0) || 
                (0 != i && diff[i - 1] < 0 && diff[i] >= 0)) {
                startPos = i;
            } else {
                continue;
            }
            
            // 由于之前 diff 计算结果的保证，肯定可以从开始位置出发，到达下一个加油站
            // 计算到达下一个加油站之后剩余的油量
            gasLeft = gas[startPos] - cost[startPos] + gas[(startPos + 1) % vecSize];
            // 更新位置为从开始位置出发之后的下一个加油站
            nowPos = (startPos + 1) % vecSize;
            nextPos = (startPos + 2) % vecSize;
            while(nowPos != startPos) {
                // 确认是否可以到达下一站
                if (gasLeft < cost[nowPos]) {
                    break;
                }
                // 计算到达下一个加油站之后剩余的油量
                gasLeft = gasLeft - cost[nowPos] + gas[nextPos];
                nowPos = (nowPos + 1) % vecSize;
                nextPos = (nextPos + 1) % vecSize;
            }
            if (nowPos == startPos) {
                return startPos;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> gas = {2, 3, 4,};
    vector<int> cost = {3, 4, 3};

    cout << solution.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
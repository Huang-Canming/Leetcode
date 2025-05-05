#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getNumTreesCnt(int minNum, int maxNum, vector<vector<int>> &subTrees) {
        if (-1 != subTrees[minNum - 1][maxNum - 1]) {
            return subTrees[minNum - 1][maxNum - 1];
        }

        int res = 0, leftCnt = 0, rightCnt = 0;
        for (int i = minNum; i <= maxNum; i++) {
            if (i - 1 > minNum) {
                leftCnt = getNumTreesCnt(minNum, i - 1, subTrees);
            } else {
                leftCnt = 1;
            }

            if (i + 1 < maxNum) {
                rightCnt = getNumTreesCnt(i + 1, maxNum, subTrees);
            } else {
                rightCnt = 1;
            }

            res += leftCnt * rightCnt;
            subTrees[minNum - 1][maxNum - 1] = res;
        }
        return res;
    }

    int numTrees(int n) {
        vector<vector<int>> subTrees(n, vector<int>(n, -1));
        int res = getNumTreesCnt(1, n, subTrees);
        return res;
    }
};

int main() {
    Solution solu;
    cout << solu.numTrees(3) << endl;
    cout << solu.numTrees(1) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution_OverTime {
private:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}};
public:
    void goEnd(vector<vector<int>>& grid, int curX, int curY, int curSum, int& minPath) {
        int m = grid.size();
        int n = grid[0].size();
        if (curX >= m || curY >= n) {
            return;
        }

        curSum += grid[curX][curY];
        if (curX == m - 1 && curY == n - 1) {
            minPath = min(curSum, minPath);
            return;
        }

        for (int i = 0; i < 2; i++) {
            goEnd(grid, curX + dirs[i][0], curY + dirs[i][1], curSum, minPath);
        }

        return;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int curX = 0, curY = 0, curSum = 0;
        int minPath = 200 * 200 * 200;
        goEnd(grid, curX, curY, curSum, minPath);
        return minPath;
    }
};

class Solution {
public:
    int getSum(vector<vector<int>>& grid, int m, int n, int x, int y, 
                vector<vector<int>> &subSum) {
        if (-1 != subSum[x][y]) {
            return subSum[x][y];
        }

        // f(x, y) = grid(x, y) + min{f(x + 1, y), f(x, y + 1)};
        int res = grid[x][y], subSumRight = -1, subSumDown = -1;
        if (x + 1 < m) {
            // 向下走
            subSumDown = getSum(grid, m, n, x + 1, y, subSum);
            res = grid[x][y] + subSumDown;
        }

        if (y + 1 < n) {
            // 向右走
            subSumRight = getSum(grid, m, n, x, y + 1, subSum);
            if (x + 1 < m) {
                // 比较向下走和向右走
                res = grid[x][y] + min(subSumRight, subSumDown);
            } else {
                res = grid[x][y] + subSumRight;
            }
        }

        subSum[x][y] = res;
        return res;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> subSum(m, vector<int>(n, -1));
        
        res = getSum(grid, m, n, 0, 0, subSum);
        return res;
    }
};

int main () {
    Solution solu;
    vector<vector<int>> grid = {{5,0,1,1,2,1,0,1,3,6,3,0,7,3,3,3,1},{1,4,1,8,5,5,5,6,8,7,0,4,3,9,9,6,0},{2,8,3,3,1,6,1,4,9,0,9,2,3,3,3,8,4},{3,5,1,9,3,0,8,3,4,3,4,6,9,6,8,9,9},{3,0,7,4,6,6,4,6,8,8,9,3,8,3,9,3,4},{8,8,6,8,3,3,1,7,9,3,3,9,2,4,3,5,1},{7,1,0,4,7,8,4,6,4,2,1,3,7,8,3,5,4},{3,0,9,6,7,8,9,2,0,4,6,3,9,7,2,0,7},{8,0,8,2,6,4,4,0,9,3,8,4,0,4,7,0,4},{3,7,4,5,9,4,9,7,9,8,7,4,0,4,2,0,4},{5,9,0,1,9,1,5,9,5,5,3,4,6,9,8,5,6},{5,7,2,4,4,4,2,1,8,4,8,0,5,4,7,4,7},{9,5,8,6,4,4,3,9,8,1,1,8,7,7,3,6,9},{7,2,3,1,6,3,6,6,6,3,2,3,9,9,4,4,8}};
    cout << solu.minPathSum(grid) << endl;
    return 0;
}
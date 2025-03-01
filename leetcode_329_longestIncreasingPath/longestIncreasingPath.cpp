#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> searchDirection = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    int matrixDfs(vector<vector<int>>& matrix, int m, int n, int i, int j, vector<vector<int>>& searchRes) {
        if (-1 != searchRes[i][j]) {
            return searchRes[i][j];
        }

        searchRes[i][j] = 1;
        for (pair<int, int> direction : searchDirection) {
            int nextI = i + direction.first;
            int nextJ = j + direction.second;
            // 判断条件：在矩阵范围内 && 下一个节点的值大于当前节点的值
            if (0 <= nextI && nextI < m && 0 <= nextJ && nextJ < n && matrix[i][j] < matrix[nextI][nextJ]) {
                // 搜索下一个节点
                int len = matrixDfs(matrix, m, n, nextI, nextJ, searchRes);
                searchRes[i][j] = max(searchRes[i][j], len + 1);
            }
        }

        return searchRes[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> searchRes(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxLen = matrixDfs(matrix, m, n, i, j, searchRes);
                res = max(res, maxLen);
            }
        }

        return res;
    }
};

int main () {
    Solution solu;
    vector<vector<int>> matrix1 = {{9,9,4},{6,6,8},{2,1,1}};
    cout << solu.longestIncreasingPath(matrix1) << endl;

    vector<vector<int>> matrix2 = {{3,4,5},{3,2,6},{2,2,1}};
    cout << solu.longestIncreasingPath(matrix2) << endl;

    vector<vector<int>> matrix3 = {{1}};
    cout << solu.longestIncreasingPath(matrix3) << endl;

    return 0;
}
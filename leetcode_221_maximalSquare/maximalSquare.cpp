#include <iostream>
#include <vector>
#if 0
#include <cmath>
#else
#include <algorithm>
#endif

using namespace std;

class Solution {
public:
    #if 0
    // 暴力解法超时
    void searchSquare(vector<vector<char>>& matrix, int startX, int startY, int endX, int endY, int &size) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (endX >= matrix.size() || endY >= matrix[0].size()) {
            return;
        }
        if ('0' == matrix[endX][endY]) {
            return;
        }
        
        // (startX, endY) -> (endX, endY)
        for (int i = startX; i < endX; i++) {
            if ('0' == matrix[i][endY]) {
                return;
            }
        }
        
        // (endX, startY) -> (endX, endY)
        for (int j = startY; j < endY; j++) {
            if ('0' == matrix[endX][j]) {
                return;
            }
        }
        size = pow((endX - startX + 1), 2);
        searchSquare(matrix, startX, startY, endX + 1, endY + 1, size);
        return;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSize = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        // 遍历矩形（从上往下，从左到右），找到 1 作为左上角
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ('1' == matrix[i][j]) {
                    int size = 1;
                    // 向 右下 方做深度优先搜索
                    searchSquare(matrix, i, j, i + 1, j + 1, size);
                    if (size > maxSize) {
                        maxSize = size;
                    }
                }
            }
        }
        
        return maxSize;
    }
    #else
    // 动态规划
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSide = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        // 遍历矩形（从上往下，从左到右），找到 1 作为左上角
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                 if ('1' == matrix[i][j]) {
                    if (0 == i || 0 == j) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                 }
            }
        }
        return maxSide * maxSide;
    }
    #endif
};

int main() {
    Solution s;
	vector<vector<char>> matrix1 = {{'1', '0', '1', '0', '0'},
								    {'1', '0', '1', '1', '1'},
								    {'1', '1', '1', '1', '1'},
								    {'1', '0', '0', '1', '0'}};
	cout << s.maximalSquare(matrix1) << endl;

    vector<vector<char>> matrix2 = {{'1', '1'},
                                    {'1', '1'}};
	cout << s.maximalSquare(matrix2) << endl;

    vector<vector<char>> matrix3 = {{'1','0','1','1','0','1'},
                                    {'1','1','1','1','1','1'},
                                    {'0','1','1','0','1','1'},
                                    {'1','1','1','0','1','0'},
                                    {'0','1','1','1','1','1'},
                                    {'1','1','0','1','1','1'}};
	cout << s.maximalSquare(matrix3) << endl;

    return 0;
}


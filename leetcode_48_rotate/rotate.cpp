#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowSize = (int)matrix[0].size();

        // 先横向翻转
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < rowSize / 2; j++)
            {
                swap(matrix[i][j], matrix[i][rowSize - j - 1]);
            }
        }

        // 再按左下到右上的对角线翻转
        for (int i = 0; i < rowSize - 1; i++)
        {
            for (int j = 0; j < rowSize - i - 1; j++)
            {
                swap(matrix[i][j], matrix[rowSize - j - 1][rowSize - i - 1]);
            }
        }

        return;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    solution.rotate(matrix1);
    solution.rotate(matrix2);

    return 0;
}
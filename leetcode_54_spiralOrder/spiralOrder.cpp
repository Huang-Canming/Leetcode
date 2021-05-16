#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = (int)matrix.size() - 1;
        int left = 0, right = (int)matrix[0].size() -1;
        int elemNum = (bottom + 1) * (right + 1);
        vector<int> res;

        while ((int)res.size() < elemNum)
        {
            // (top, left) TO (top, right)
            for (int i = top, j = left; j <= right; j++)
            {
                res.push_back(matrix[i][j]);
            }

            // (top + 1, right) TO (bottom, right)
            for (int i = top + 1, j = right; i <= bottom; i++)
            {
                res.push_back(matrix[i][j]);
            }

            // 最后遍历到只剩下一行或者一列的时候，跳过后面的两个循环，避免重复遍历
            if (left == right || top == bottom)
            {
                continue;
            }

            // (bottom, right - 1) TO (bottom, left)
            for (int i = bottom, j = right - 1; j >= left; j--)
            {
                res.push_back(matrix[i][j]);
            }

            // (bottom - 1, left) TO (top + 1, left)
            for (int i = bottom - 1, j = left; i >= top + 1; i--)
            {
                res.push_back(matrix[i][j]);
            }

            top++;
            bottom--;
            left++;
            right--;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> res;

    res = solution.spiralOrder(matrix);

    for(int elem : res)
    {
        cout << elem << endl;
    }

    return 0;
}
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool bClearZeroRow = false, bClearZeroCol = false;
        int rowNum = (int)matrix.size(), colNum = (int)matrix[0].size();

        for (int j = 0; j < colNum; j++)
        {
            if (0 == matrix[0][j])
            {
                bClearZeroRow = true;
                break;
            }
        }

        for (int i = 0; i < rowNum; i++)
        {
            if (0 == matrix[i][0])
            {
                bClearZeroCol = true;
                break;
            }
        }

        for (int i = 1; i < rowNum; i++)
        {
            for (int j = 1; j < colNum; j++)
            {
                if (0 == matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        } 

        for (int i = 1; i < rowNum; i++)
        {
            for (int j = 1; j < colNum; j++)
            {
                if (0 == matrix[0][j] || 0 == matrix[i][0])
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (true == bClearZeroRow)
        {
            for (int j = 0; j < colNum; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (true == bClearZeroCol)
        {
            for (int i = 0; i < rowNum; i++)
            {
                matrix[i][0] = 0;
            }
        }

        return;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 0}};

    solution.setZeroes(matrix);

    return 0;
}
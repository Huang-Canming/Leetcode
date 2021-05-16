#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool vecBinarySearch(vector<int> &row, int colSize, int target){

        int left = 0, mid = 0,  right = colSize - 1;

        while (left <= right)
        {
            mid = (left + right) / 2;
            if (row[mid] == target)
            {
                return true;
            }
            else if (row[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rowSize = (int)matrix.size();
        int colSize = (int)matrix[0].size();

        for (int i = 0; i < rowSize; i++)
        {
            if (target < matrix[i][0] || target > matrix[i][colSize - 1])
            {
                continue;
            }

            if (vecBinarySearch(matrix[i], colSize, target))
            {
                return true;
            }
        }

        return false;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    cout << solution.searchMatrix(matrix, 7) << endl;

    return 0;
}
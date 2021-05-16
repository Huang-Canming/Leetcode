#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool duplicatedDigit(vector<char> vecDigit){
        int vecSize = (int)vecDigit.size();

        sort(vecDigit.begin(), vecDigit.end());
        for (int i = 0; i < vecSize - 1; i++)
        {
            if ('.' != vecDigit[i] && vecDigit[i] == vecDigit[i + 1])
            {
                return true;
            }
        }

        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        bool bDuplicated = false;

        /* 按行判断 */
        for (int i = 0; i < 9; i++)
        {
            bDuplicated = duplicatedDigit(board[i]);
            if (true == bDuplicated)
            {
                /* 存在重复数字，数独无效 */
                return false;
            }
        }

        /* 按列判断 */
        for (int j = 0; j < 9; j++)
        {
            vector<char> column(9, '.');
            for (int i = 0; i < 9; i++)
            {
                column[i] = board[i][j];
            }
            bDuplicated = duplicatedDigit(column);
            if (true == bDuplicated)
            {
                /* 存在重复数字，数独无效 */
                return false;
            }
        }

        /* 按3*3九宫格判断 */
        for (int m = 0; m < 9; m += 3)
        {
            for (int n = 0; n < 9; n += 3)
            {
                vector<char> square;
                for (int i = m; i < m + 3; i++)
                {
                    for (int j = n; j < n + 3; j++)
                    {
                        square.push_back(board[i][j]);
                    }
                }
                bDuplicated = duplicatedDigit(square);
                if (true == bDuplicated)
                {
                    /* 存在重复数字，数独无效 */
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> board1 = {{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                                   {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                                   {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                                   {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                                   {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                                   {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                                   {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};


    cout << solution.isValidSudoku(board1) << endl;

    return 0;
}
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& board, int rowSize, int colSize, int x, int y)
    {
        if (x < 0 || x > rowSize - 1 || y < 0 || y > colSize - 1)
        {
            return;
        }

        if ('O' != board[x][y])
        {
            return;
        }

        board[x][y] = '#';

        dfs(board, rowSize, colSize, x - 1, y);
        dfs(board, rowSize, colSize, x, y - 1);
        dfs(board, rowSize, colSize, x + 1, y);
        dfs(board, rowSize, colSize, x, y + 1);

        return;
    }

    void solve(vector<vector<char>>& board) {
        int rowSize = (int)board.size(), colSize = (int)board[0].size();

        for (int y = 0; y < colSize; y++)
        {
            dfs(board, rowSize, colSize, 0, y);
            dfs(board, rowSize, colSize, rowSize - 1, y);
        }

        for (int x = 1; x < rowSize - 1; x++)
        {
            dfs(board, rowSize, colSize, x, 0);
            dfs(board, rowSize, colSize, x, colSize - 1);
        }

        for (int x = 0; x < rowSize; x++)
        {
            for (int y = 0; y < colSize; y++)
            {
                if ('O' == board[x][y])
                {
                    board[x][y] = 'X';
                }
            }
        }

        for (int x = 0; x < rowSize; x++)
        {
            for (int y = 0; y < colSize; y++)
            {
                if ('#' == board[x][y])
                {
                    board[x][y] = 'O';
                }
            }
        }

        return;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board1 =
        {{'X', 'X', 'X', 'X'},
         {'X', 'O', 'O', 'X'},
         {'X', 'X', 'O', 'X'},
         {'X', 'O', 'X', 'X'}};
    vector<vector<char>> board2 =
        {{'O', 'X', 'X', 'O', 'X'},
         {'X', 'O', 'O', 'X', 'O'},
         {'X', 'O', 'X', 'O', 'X'},
         {'O', 'X', 'O', 'O', 'O'},
         {'X', 'X', 'O', 'X', 'O'}};

    solution.solve(board2);

    return 0;
}
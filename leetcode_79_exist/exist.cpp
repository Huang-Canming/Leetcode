#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    #if 0
    // 官方解答
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
    #endif

    bool findElemAround(vector<vector<char>>& board, vector<vector<int>>& used, int row, int col, string word)
    {
        if ("" == word)
        {
            return true;
        }

        int rowSize = (int)board.size(), colSize = (int)board[0].size();
        int wordLen = (int)word.size();
        string subWord = word.substr(1, wordLen - 1);

        if (row - 1 >= 0 && 1 != used[row - 1][col] && word[0] == board[row - 1][col])
        {
            used[row - 1][col] = 1;
            if (findElemAround(board, used, row - 1, col, subWord))
            {
                return true;
            }
            used[row - 1][col] = 0;
        }

        if (col - 1 >= 0 && 1 != used[row][col - 1] && word[0] == board[row][col - 1])
        {
            used[row][col - 1] = 1;
            if (findElemAround(board, used, row, col - 1, subWord))
            {
                return true;
            }
            used[row][col - 1] = 0;
        }

        if (row + 1 < rowSize && 1 != used[row + 1][col] && word[0] == board[row + 1][col])
        {
            used[row + 1][col] = 1;
            if (findElemAround(board, used, row + 1, col, subWord))
            {
                return true;
            }
            used[row + 1][col] = 0;
        }

        if (col + 1 < colSize && 1 != used[row][col + 1] && word[0] == board[row][col + 1])
        {
            used[row][col + 1] = 1;
            if (findElemAround(board, used, row, col + 1, subWord))
            {
                return true;
            }
            used[row][col + 1] = 0;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rowSize = (int)board.size(), colSize = (int)board[0].size();
        vector<vector<int>> used(rowSize, vector<int>(colSize, 0));

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (word[0] != board[i][j])
                {
                    continue;
                }

                used[i][j] = 1;
                string subWord = word.substr(1, word.size() - 1);
                if (findElemAround(board, used, i, j, subWord))
                {
                    return true;
                }
                used[i][j] = 0;
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    cout << solution.exist(board, "ABCCED") << endl;
    cout << solution.exist(board, "SEE") << endl;
    cout << solution.exist(board, "ABCB") << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findLandByDFS(int i, int j, vector<vector<char>>& grid) {
        int rowNum = (int)grid.size(), colNum = (int)grid[0].size();

        grid[i][j] = '0';
        if (i - 1 >= 0 && '1' == grid[i - 1][j]) {
            findLandByDFS(i - 1, j, grid);
        }
        if (i + 1 < rowNum && '1' == grid[i + 1][j]) {
            findLandByDFS(i + 1, j, grid);
        }
        if (j - 1 >= 0 && '1' == grid[i][j - 1]) {
            findLandByDFS(i, j - 1, grid);
        }
        if (j + 1 < colNum && '1' == grid[i][j + 1]) {
            findLandByDFS(i, j + 1, grid);
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rowNum = (int)grid.size(), colNum = (int)grid[0].size();
        int isLandNum = 0;

        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if ('1' == grid[i][j]) {
                    findLandByDFS(i, j, grid);
                    isLandNum++;
                }
            }
        }

        return isLandNum;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}};

    vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};

    cout << solution.numIslands(grid1) << endl;
    cout << solution.numIslands(grid2) << endl;

    return 0;
}
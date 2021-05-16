#include <vector>

using namespace std;

class Solution {
public:
    int traverseArround(vector<vector<int>>& board, int x, int y){
        int aliveCellNum = 0, rowSize = (int)board.size(), colSize = (int)board[0].size();
        for (int i = -1; i < 2; i++){
            if (x + i < 0 || x + i >= rowSize){
                continue;
            }

            for (int j = -1; j < 2; j++){
                if (y + j < 0 || y + j >= colSize){
                    continue;
                }

                if (0 == i && 0 == j){
                    continue;
                }

                if (1 == board[x + i][y + j] || 3  == board[x + i][y + j]){
                    aliveCellNum++;
                }
            }
        }
        return aliveCellNum;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int aliveCellNum = 0, rowSize = (int)board.size(), colSize = (int)board[0].size();
        
        for (int x = 0; x < rowSize; x++){
            for (int y = 0; y < colSize; y++){
                aliveCellNum = traverseArround(board, x, y);
                // 复活的细胞标记为 2
                if (0 == board[x][y] && 3 == aliveCellNum){
                    board[x][y] = 2;
                // 被动死亡的细胞标记为 3
                } else if (1 == board[x][y] && (aliveCellNum < 2 || aliveCellNum > 3)){
                    board[x][y] = 3;
                }
            }
        }

        // 恢复 0 和 1
        for (int x = 0; x < rowSize; x++){
            for (int y = 0; y < colSize; y++){
                if (2 == board[x][y]){
                    board[x][y] = 1;
                } else if (3 == board[x][y]){
                    board[x][y] = 0;
                }
            }
        }

        return;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    solution.gameOfLife(board);
    return 0;
}
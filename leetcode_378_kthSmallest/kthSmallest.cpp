#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int vecSize = matrix.size();
        priority_queue<int, vector<int>, less<int>> numQueue;

        for (int i = vecSize - 1; i >= 0; i--) {
            for (int j = vecSize - 1; j >= 0; j--) {
                if (numQueue.size() >= k) {
                    numQueue.pop();
                }
                numQueue.push(matrix[i][j]);
            }
        }

        return numQueue.top();
    }
};

int main () {
    Solution solu;
    vector<vector<int>> matrix1 = {{1,5,9},{10,11,13},{12,13,15}};
    vector<vector<int>> matrix2 = {{-5}};
    
    cout << solu.kthSmallest(matrix1, 8) << endl;
    cout << solu.kthSmallest(matrix2, 1) << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquaresDP(int n){
        vector<int> vecDP(n + 1, 0);
        for (int i = 1; i <= n; i++){            
            // 最坏的情况都是由 1 的平方组成
            vecDP[i] = i;                   
            for (int j = 1; j * j <= i; j++) {
                // 动态规划公式
                vecDP[i] = min(vecDP[i], vecDP[i - j * j] + 1);
            }
        }

        return vecDP[n];
    }
};

int main(){
    Solution solution;
    cout << solution.numSquaresDP(12) << endl;

    return 0;
}
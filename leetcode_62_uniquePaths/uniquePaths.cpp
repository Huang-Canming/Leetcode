#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int getPathsRecusion(int m, int n, vector<vector<int>> &dp)
    {
        if (1 == m || 1 == n)
        {
            return 1;
        }

        if (0 == dp[m - 1][n - 1])
        {
            dp[m - 1][n - 1] = getPathsRecusion(m - 1, n, dp) + getPathsRecusion(m, n - 1, dp);
        }

        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {

        if (1 == m || 1 == n)
        {
            return 1;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));

        return getPathsRecusion(m - 1, n, dp) + getPathsRecusion(m, n - 1, dp);
    }
};

int main()
{
    Solution solution;

    cout << solution.uniquePaths(3, 7) << endl;

    return 0;
}
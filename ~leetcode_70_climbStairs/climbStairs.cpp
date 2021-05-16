#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs_DPTable(int n) {

        /* DP Table */
        vector<int> vAns(n + 1, 0);

        vAns[0] = 1;
        vAns[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            /* 状态转移方程 */
            vAns[i] = vAns[i - 1] + vAns[i - 2];
        }

        return vAns[n];
    }
};

int main()
{
    Solution solution;

    cout << solution.climbStairs_DPTable(2) << endl;
    cout << solution.climbStairs_DPTable(3) << endl;
    cout << solution.climbStairs_DPTable(4) << endl;

    return 0;
}
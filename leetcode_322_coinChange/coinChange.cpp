#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> subRes = vector<int>(10001, 0);
public:

    int coinChange(vector<int>& coins, int amount) {

        if (0 == amount)
        {
            return 0;
        }

        if (0 != subRes[amount])
        {
            return subRes[amount];
        }

        int vecSize = coins.size();
        int leastCoinsNum = -1;
        for (int i = 0; i < vecSize; i++)
        {
            if (coins[i] == amount)
            {
                leastCoinsNum = 1;
                break;
            }
            else if (coins[i] < amount)
            {
                int subCoinNum = coinChange(coins, amount - coins[i]);
                subRes[amount - coins[i]] = subCoinNum;
                if ((-1 != subCoinNum) && (-1 == leastCoinsNum || 1 + subCoinNum < leastCoinsNum))
                {
                    leastCoinsNum = 1 + subCoinNum;
                }
            }
        }

        subRes[amount] = leastCoinsNum;
        return leastCoinsNum;
    }
};

int main()
{
    vector<int> coins = {1};
    int amount = 10000;
    Solution sol;
    int res = -2;

    res = sol.coinChange(coins, amount);
    cout << res << endl;
    return 0;
}
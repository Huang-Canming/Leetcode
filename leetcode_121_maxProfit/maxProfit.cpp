#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0;
        int len = (int) prices.size();

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (prices[j] - prices[i] > res)
                {
                    res = prices[j] - prices[i];
                }
            }
        }

        return res;
    }

    int maxProfit_DP(vector<int>& prices) {

        if (0 == prices.size())
        {
            return 0;
        }

        int minPrice = prices[0];
        int dayNum = prices.size();
        vector<int> dp(dayNum, 0);
        
        for (int i = 1; i < dayNum; i++)
        {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }

        return dp[dayNum - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << solution.maxProfit_DP(prices) << endl;

    return 0;
}
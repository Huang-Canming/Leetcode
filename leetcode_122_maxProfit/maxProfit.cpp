#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int vSize = (int)prices.size();
        int res = 0, buy = 0, sell = 0;
        bool bContain = false;

        if (0 == vSize || 1 == vSize)
        {
            return res;
        }

        for (int i = 0; i < vSize; i++)
        {
            if (vSize - 1 == i)
            {
                if (true == bContain)
                {
                    res += prices[vSize - 1] - prices[buy];
                }
                continue;
            }

            if (prices[i + 1] > prices[i] && false == bContain)
            {
                buy = i;
                bContain = true;
            }
            else if (prices[i + 1] < prices[i] && true == bContain)
            {
                sell = i;
                res += prices[sell] - prices[buy];
                bContain = false;
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> prices = {1, 2, 3, 4, 5};

    cout << solution.maxProfit(prices) << endl;

    return 0;
}
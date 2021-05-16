#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> vRes;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> vSubRes;

            for (int j = 0; j <= i; j++)
            {
                if (0 == j || i == j)
                {
                    vSubRes.push_back(1);
                }
                else
                {
                    vSubRes.push_back(vRes[i - 1][j - 1] + vRes[i - 1][j]);
                }
            }

            vRes.push_back(vSubRes);
        }

        return vRes;
    }
};

int main()
{
    Solution solution;

    solution.generate(5);
    return 0;
}
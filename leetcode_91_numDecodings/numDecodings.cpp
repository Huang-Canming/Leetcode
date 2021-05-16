#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int recursionDecoding(string &s, int pos, vector<int>& dp) {
        int res = 0, strSize = (int)s.size();

        if (pos > strSize - 1)
        {
            return 1;
        }

        if (-1 != dp[pos])
        {
            return dp[pos];
        }

        if ('0' == s[pos])
        {
            return 0;
        }

        res += recursionDecoding(s, pos + 1, dp);

        if (pos < strSize - 1 && s.substr(pos, 2) <= "26")
        {
            res += recursionDecoding(s, pos + 2, dp);
        }

        dp[pos] = res;
        return res;
    }

    int numDecodings(string s) {
        int res = 0, strSize = (int)s.size();
        vector<int> dp(strSize, -1);

        if ('0' == s[0])
        {
            return 0;
        }

        res = recursionDecoding(s, 0, dp);
        return res;
    }
};

int main()
{
    Solution solution;

    cout << solution.numDecodings("10") << endl;
    cout << solution.numDecodings("12") << endl;
    cout << solution.numDecodings("226") << endl;

    return 0;
}
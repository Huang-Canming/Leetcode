#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int strSubPos, int strLen)
    {
        int left = 0, right = 0;

        for (int i = 0; i < strLen / 2; i++)
        {
            left = strSubPos + i;
            right = strSubPos + strLen - i - 1;

            if (isdigit(s[left]) && s[left] != s[right])
            {
                return false;
            }
            else if (isdigit(s[left]) && s[left] == s[right])
            {
                continue;
            }
            else if (isalpha(s[left]) && tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else if (isalpha(s[left]) && tolower(s[left]) == tolower(s[right]))
            {
                continue;
            }
        }

        return true;
    }

    string longestPalindrome(string s) {
        int res = 0, sLen = 0, strSubPos = 0;
        string strSub, strRes;

        sLen = (int)s.size();
        while (sLen - strSubPos > res)
        {
            for (int i = res + 1; i <= sLen - strSubPos; i++)
            {
                if (isPalindrome(s, strSubPos, i))
                {
                    res = i;
                    strRes = s.substr(strSubPos, i);
                }
            }

            strSubPos++;
        }

        return strRes;
    }

    string longestPalindrome_DP(string s) {
        int strLen = s.size(), i = 0, j = 0, maxPalindromeLen = 0, longestPalindromeStart = 0;
        vector<vector<int>> dp(strLen, vector<int>(strLen));

        for (int subStrLen = 1; subStrLen <= strLen; subStrLen++)
        {
            for (i = 0; i <= strLen - subStrLen; i++)
            {
                j = i + subStrLen - 1;
                if (1 == subStrLen)
                {
                    dp[i][j] = 1;
                }
                else if (2 == subStrLen)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if (subStrLen > maxPalindromeLen && 1 == dp[i][j])
                {
                    maxPalindromeLen = subStrLen;
                    longestPalindromeStart = i;
                }
            }
        }

        return s.substr(longestPalindromeStart, maxPalindromeLen);
    }
};

int main()
{
    Solution solution;
    string s = "a";

    cout << solution.longestPalindrome_DP(s) << endl;

    return 0;
}
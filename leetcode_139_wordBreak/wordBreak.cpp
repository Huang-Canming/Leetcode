#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int strSize = (int)s.size();
        vector<bool> dp(strSize + 1, false);
        unordered_set<string> setWordDict;

        for (auto str : wordDict)
        {
            setWordDict.insert(str);
        }

        dp[0] = true;
        for (int i = 1; i <= strSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (false == dp[j])
                {
                    continue;
                }

                if (setWordDict.find(s.substr(j, i -j)) != setWordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[strSize];
    }
};

int main()
{
    Solution solution;
    string s1 = "leetcode";
    string s2 = "applepenapple";
    string s3 = "catsandog";

    vector<string> wordDict1 = {"leet", "code"};
    vector<string> wordDict2 = {"apple", "pen"};
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};

    cout << solution.wordBreak(s1, wordDict1) << endl;
    cout << solution.wordBreak(s2, wordDict2) << endl;
    cout << solution.wordBreak(s3, wordDict3) << endl;

    return 0;
}
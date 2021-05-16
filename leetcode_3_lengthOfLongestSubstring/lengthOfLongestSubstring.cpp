#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int resTmp = 0, res = 0;

        for (int i = 1; i <= (int) s.size(); i++)
        {
            string strSub = s.substr(0, i);
            unordered_map<char, int> charCount;

            for (int j = i - 1; j >= 0; j--)
            {
                charCount[s[j]]++;
                if (charCount[s[j]] > 1)
                {
                    break;
                }
                else
                {
                    resTmp++;
                }
            }

            resTmp > res ? res = resTmp : res = res;
            resTmp = 0;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    string str1 = "abcabcbb";

    cout << solution.lengthOfLongestSubstring(str1) << endl;

    return 0;
}
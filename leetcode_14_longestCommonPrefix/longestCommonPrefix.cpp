#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int i = 0;
        int strIndex = 0;
        string res = "";

        if (0 == strs.size())
        {
            return "";
        }

        if (1 == strs.size())
        {
            return strs[0];
        }

        for (i = 0; i < (int) strs.size(); i++)
        {
            if (strs[i] == "")
            {
                return "";
            }
        }

        while (strIndex < 200)
        {
            for (i = 1; (i < (int) strs.size()) && (strIndex < (int) strs[i].size()) && (strIndex < (int) strs[i-1].size()); i++)
            {
                if (strs[i].at(strIndex) == strs[i - 1].at(strIndex))
                {
                    continue;
                }
                else
                {
                    break;
                }
            }

            if (i == (int) strs.size())
            {
                res += strs[0].at(strIndex);
                strIndex++;
            }
            else 
            {
                break;
            }
            
        }

        return res;
    }
};

int main()
{
    Solution solution;
    //vector<string> strs = {"flower", "flow", "flight" };
    vector<string> strs = {"ab", "a" };
    cout << solution.longestCommonPrefix(strs) << endl;

    return 0;
}
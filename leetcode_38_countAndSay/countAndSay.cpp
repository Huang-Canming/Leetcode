#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {

        if (1 == n)
        {
            return "1";
        }

        int i = 0, pos = 0, count = 1, strLen = 0;
        string strTmp, strRes;

        strTmp = countAndSay(n - 1);
        strLen = (int)strTmp.size();
        while (i < strLen)
        {
            while (pos + 1 < strLen && strTmp[pos] == strTmp[pos + 1])
            {
                count++;
                pos++;
            }

            strRes = strRes + to_string(count) + strTmp[i];
            i += count;
            pos = i;
            count = 1;
        }

        return strRes;
    }
};

int main()
{
    Solution solution;

    // cout << solution.countAndSay(1) << endl;
    // cout << solution.countAndSay(2) << endl;
    // cout << solution.countAndSay(3) << endl;
    // cout << solution.countAndSay(4) << endl;
    // cout << solution.countAndSay(5) << endl;
    cout << solution.countAndSay(6) << endl;

    return 0;
}
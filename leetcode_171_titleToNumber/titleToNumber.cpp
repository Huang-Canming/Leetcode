#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {

        int strSize = s.size();
        long long int rank = 1;
        long long int res = 0;

        if (0 == strSize)
        {
            return 0;
        }

        for (int i = strSize - 1; i >= 0; i--)
        {
            res += (s[i] - 'A' + 1) * rank;
            rank = rank * 26;
        }

        return res;
    }
};

int main()
{
    string strA = "AB";
    string strB = "ZY";
    Solution solution;

    cout << solution.titleToNumber(strA) << endl;
    cout << solution.titleToNumber(strB) << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    void backtrack(vector<string>& res, string& track, map<char, int>& mpParenthesis, int parenthesisTotal)
    {
        if ((int)track.size() == parenthesisTotal * 2)
        {
            res.push_back(track);
        }

        map<char, int>::iterator itParenthesis = mpParenthesis.begin();
        for (itParenthesis = mpParenthesis.begin(); itParenthesis != mpParenthesis.end(); itParenthesis++)
        {
            /* 剪枝条件：使用的左括号数必须大于等于右括号数 */
            if (')' == itParenthesis->first && mpParenthesis[')'] >= mpParenthesis['('])
            {
                continue;
            }

            if (parenthesisTotal == itParenthesis->second)
            {
                continue;
            }

            track.push_back(itParenthesis->first);
            itParenthesis->second++;
            backtrack(res, track, mpParenthesis, parenthesisTotal);
            track.pop_back();
            itParenthesis->second--;
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        map<char, int> parenthesisUsed = {{'(', 1}, {')', 0}};
        string track = "(";
        vector<string> res;

        backtrack(res, track, parenthesisUsed, n);

        return res;
    }
};

int main()
{
    Solution solution;
    vector<string> res;

    res = solution.generateParenthesis(3);

    return 0;
}
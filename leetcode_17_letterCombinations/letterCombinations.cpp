#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int digitIndex = 1;
        char cDigit;
        string strAlpha, strComb;
        vector<string> vecStrRes;
        queue<string> queStrComb;
        unordered_map<char, string> mpKeyBoard = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
                                                  {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, 
                                                  {'8', "tuv"}, {'9', "wxyz"}};

        strAlpha = mpKeyBoard[digits[0]];
        for (int i = 0; i < (int)strAlpha.size(); i++)
        {
            queStrComb.push(strAlpha.substr(i, 1));
        }

        while (0 != queStrComb.size())
        {
            strComb = queStrComb.front();
            queStrComb.pop();
            if ((int)strComb.size() == (int)digits.size())
            {
                vecStrRes.push_back(strComb);
                continue;
            }

            if ((int)strComb.size() > digitIndex)
            {
                digitIndex++;
            }

            cDigit = digits[digitIndex];
            strAlpha = mpKeyBoard[cDigit];

            for (int i = 0; i < (int)strAlpha.size(); i++)
            {
                strComb.push_back(strAlpha[i]);
                queStrComb.push(strComb);
                strComb.pop_back();
            }
        }

        return vecStrRes;
    }
};

int main()
{
    Solution solution;

    solution.letterCombinations("234");

    return 0;
}
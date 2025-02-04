#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool judgePalindrome(string subStr){
        int strLen = subStr.length();
        for (int i = 0; i < strLen / 2; i++)
        {
            if (subStr[i] != subStr[strLen - i - 1])
            {
                return false;
            }
        }

        return true;
    }

    void getSubStr(string s, int prevLen, vector<string> &subStrTrack, vector<vector<string>> &res) {

        int strLen = s.length();
        for (int subLen = 1; subLen <= strLen - prevLen; subLen++)
        {            
            string subStr = s.substr(prevLen, subLen);                  // 选择一个子串
            bool isPalindrome = judgePalindrome(subStr);                // 判断是否是回文串
            if (true == isPalindrome)
            {
                subStrTrack.push_back(subStr);
                if (prevLen + subLen < strLen)
                {
                    getSubStr(s, prevLen + subLen, subStrTrack, res);   // 递归选择下一个子串
                }
                else
                {
                    res.push_back(subStrTrack);                         // 完成一组子串的遍历
                }
                subStrTrack.pop_back();                                 // 回退当前的选择
            }
        }

        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subStr;

        getSubStr(s, 0, subStr, res);

        return res;
    }
};

void printRes(vector<vector<string>> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j < res[i].size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]";
        if (i < res.size() - 1)
        {
            cout << ",";
        }
        else
        {
            cout << "]";
        }
    }

    cout << endl;

    return;
}

int main ()
{
    Solution solu;
    
    string str1 = "aab";
    vector<vector<string>> res1 = solu.partition(str1);
    printRes(res1);
    
    string str2 = "a";
    vector<vector<string>> res2 = solu.partition(str2);
    printRes(res2);

    return 0;
}
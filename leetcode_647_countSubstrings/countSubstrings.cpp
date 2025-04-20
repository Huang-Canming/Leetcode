#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void checkStr(string &s, int start, int end, vector<vector<int>> &record, int &panlindromeCnt) {
        if (-1 != record[start][end]) {
            // 已经完成过对子串的判断
            return;
        }

        if (s[start] != s[end]) {
            // s[start ~ end] 不是回文子串
            record[start][end] = 0;
        } else {
            if (start + 1 < end) {
                // 继续检查 s[start + 1 ~ end - 1] 是否是回文串
                checkStr(s, start + 1, end - 1, record, panlindromeCnt);
                // s[start ~ end] 的结果取决于 s[start + 1 ~ end - 1]
                record[start][end] = record[start + 1][end - 1];
            } else {
                // start、end 指向同一个字符或者指向的字符相邻
                record[start][end] = 1;
            }
            // 对于 s[start ~ end] 是回文串的情况，计数加 1
            panlindromeCnt += record[start][end];
        }
        return;
    }

    int countSubstrings(string s) {
        int sLen = s.length();
        int panlindromeCnt = 0;
        vector<vector<int>> record(sLen, vector<int>(sLen, -1));
        for (int i = 0; i < sLen; i++) {
            for (int j = i; j < sLen; j++) {
                checkStr(s, i, j, record, panlindromeCnt);
            }
        }
        
        return panlindromeCnt;
    }
};

int main () {
    Solution solu;
    string s1 = "abc";
    cout << solu.countSubstrings(s1) << endl;
    string s2 = "aaa";
    cout << solu.countSubstrings(s2) << endl;
    return 0;
}
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    void checkWords(string s, vector<string>& wordDict, unordered_set<string>& wordSet, 
                    int startPos, string brokenStr, vector<string>& res) {
        int strLen = s.length();
        for (int subLen = 1; subLen <= strLen - startPos; subLen++) {
            string subStr = s.substr(startPos, subLen);
            auto iter = wordSet.find(subStr);
            if (iter != wordSet.end()) {
                // 在字典中有对应的字符串
                string appendedStr = "";
                if (0 == brokenStr.length()) {
                    appendedStr = subStr;
                } else {
                    appendedStr = brokenStr + " " + subStr;
                }
                
                if (subLen == strLen - startPos) {
                    // 已经处理到了原字符串的结尾
                    res.push_back(appendedStr);
                    return;
                } else {
                    // 处理后续字符串
                    checkWords(s, wordDict, wordSet, startPos + subLen, appendedStr, res);
                }
            }
        }

        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;

        // 生成哈希表，加速查找
        int wordCnt = wordDict.size();
        unordered_set<string> wordSet;
        for (int i = 0; i < wordCnt; i++) {
            wordSet.insert(wordDict[i]);
        }

        checkWords(s, wordDict, wordSet, 0, "", res);

        return res;
    }
};

int main () {
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    Solution solu;
    vector<string> res = solu.wordBreak(s, wordDict);
    for (string brokenStr : res) {
        cout << brokenStr << endl;
    }

    return 0;
}
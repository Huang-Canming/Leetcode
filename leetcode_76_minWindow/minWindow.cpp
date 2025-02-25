#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        pair<int, int> miniWow = {0, 0};

        int tLen = t.length();
        int totalCharCnt = 0;
        unordered_map<char, pair<int, int>> tCharCnt;
        for (int i = 0; i < tLen; i++) {
            if (tCharCnt.end() == tCharCnt.find(t[i])) {
                tCharCnt[t[i]] = pair<int, int>(1, 0);
                totalCharCnt++;
            } else {
                tCharCnt[t[i]].first++;
            }
        }

        // 从左开始，找到第一个包含所有 t 中字符的窗口
        int right = 0;
        int sLen = s.length();
        int fullCharCnt = 0;
        for (right = 0; right < sLen; right++) {
            if (tCharCnt.end() != tCharCnt.find(s[right])) {
                tCharCnt[s[right]].second++;
                if (tCharCnt[s[right]].first == tCharCnt[s[right]].second) {
                    fullCharCnt++;
                    if (fullCharCnt == totalCharCnt) {
                        break;
                    }
                }
            }
        }

        if (fullCharCnt < totalCharCnt)
        {
            // s 不满足
            return "";
        }
        
        // 左边界向右移动，找到最小窗口
        int left = 0;
        for (left = 0; left <= right; left++) {
            if (tCharCnt.end() != tCharCnt.find(s[left])) {
                if (tCharCnt[s[left]].second > tCharCnt[s[left]].first) {
                    tCharCnt[s[left]].second--;
                } else {
                    break;
                }
            }
        }

        miniWow.first = left;
        miniWow.second = right;

        for (right = right + 1; right < sLen; right++) {
            // 窗口左、右边界同时向右移动 1，判断是否能包含 t 中所有字符
            if (tCharCnt.end() != tCharCnt.find(s[right])) {
                tCharCnt[s[right]].second++;

                // 如果包含，左边界向右移动，找到最小窗口
                while (left <= right) {
                    if (tCharCnt.end() != tCharCnt.find(s[left])) {
                        if (tCharCnt[s[left]].second > tCharCnt[s[left]].first) {
                            tCharCnt[s[left]].second--;
                            left++;
                        } else {
                            break;
                        }
                    } else {
                        left++;
                    }
                }

                // 检查是否找到了更小的子串
                if (miniWow.second - miniWow.first > right - left) {
                    miniWow.first = left;
                    miniWow.second = right;
                }
            }
        }

        return s.substr(miniWow.first, miniWow.second - miniWow.first + 1);
    } 
};

int main () {
    Solution solu;
    cout << solu.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
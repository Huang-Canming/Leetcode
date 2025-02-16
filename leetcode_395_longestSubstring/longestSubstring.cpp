#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int checkSubStr(string s, int k) {
        vector<int> cnt(26, 0);
        int index = 0;
        int len = 0;
        int res = 0;

        // 统计每个字符出现的次数
        for (char c : s) {
            index = c - 'a';
            cnt[index]++;
        }

        // 找到出现次数小于 k 的字符
        for (index = 0; index < cnt.size(); index++) {
            if (0 < cnt[index] && cnt[index] < k) {
                break;
            }
        }

        if (cnt.size() == index) {
            // 不存在出现次数小于 k 的元素
            return s.length();
        } else {
            // 拆分成不包含 “出现次数小于 k 的元素” 的子串
            stringstream ss(s);
            string splitStr;
            char c = 'a' + index;
            while (getline(ss, splitStr, c)) {
                len = checkSubStr(splitStr, k);
                res = max(len, res);
            }
            return res;
        }
    }

    int longestSubstring(string s, int k) {
        int res = checkSubStr(s, k);
        return res;
    }
};

int main () {
    Solution solu;
    cout << solu.longestSubstring("aaabb", 3) << endl;
    return 0;
}
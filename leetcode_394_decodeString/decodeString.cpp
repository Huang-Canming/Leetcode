#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<char> stkTotal;
        stack<char> stkSubStr;
        stack<char> stkNumber;

        for (char c : s) {
            if (']' != c) {
                stkTotal.push(c);
                continue;
            }

            string resvStr = "";
            while ('[' != stkTotal.top()) {     // 弹出 '[' 和 ']' 之间的字符，加入 resvStr
                resvStr += stkTotal.top();
                stkTotal.pop();
            }
            stkTotal.pop();                     // 弹出 '['

            while (!stkTotal.empty() && '0' <= stkTotal.top() && stkTotal.top() <= '9') {
                stkNumber.push(stkTotal.top()); // 把 '[' 之前的数字字符压入 stkNumber
                stkTotal.pop();
            }

            int num = 0;                        // 把 stkNumber 中的字符转换成数字 num
            string numStr = "";
            while (!stkNumber.empty()) {
                numStr += stkNumber.top();
                stkNumber.pop();
            }
            num = atoi(numStr.c_str());

            for (int i = 0; i < num; i++) {     // 按照'['前的数字，重复加入字符串
                for (int j = resvStr.length() - 1; j >= 0; j--) {
                    stkTotal.push(resvStr[j]);
                }
            }
        }

        while (!stkTotal.empty()) {
            stkSubStr.push(stkTotal.top());
            stkTotal.pop();
        }
        while (!stkSubStr.empty()) {
            res += stkSubStr.top();
            stkSubStr.pop();
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("2[abc]3[cd]ef") << endl;
    cout << s.decodeString("abc3[cd]xyz") << endl;
    cout << s.decodeString("100[leetcode]") << endl;
    return 0;
}
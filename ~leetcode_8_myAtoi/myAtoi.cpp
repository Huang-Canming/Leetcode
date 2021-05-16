#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>

using namespace std;


class Solution {
public:

    unordered_map<string, vector<string>> stateTbl = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

    int myAtoi(string str) {
        int sign = 1;
        long long ans = 0;
        string state = "start";

        for (char c : str)
        {
            state = stateTbl[state][get_col(c)];
            if (state == "in_number") {
                ans = ans * 10 + c - '0';
                ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
            }
            else if (state == "signed")
            {
                sign = (c == '+' ? 1 : -1);
            }
            else if (state == "end")
            {
                break;
            }
        }
        return sign * ans;
    }
};

int main()
{
    Solution solution;

    cout << solution.myAtoi("+-12") << endl;

    return 0;
}
#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if ("" == s)
        {
            return true;
        }

        stack<char> staLeftBrackets;
        unordered_map<char, char> mpMatchBrackets = {{')','('}, {'}', '{'}, {']', '['}};
        unordered_map<char, char>::iterator mpIter = mpMatchBrackets.end();

        for (int i = 0; i < (int)s.length(); i++)
        {
            if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
            {
                staLeftBrackets.push(s.at(i));
                continue;
            }

            mpIter = mpMatchBrackets.find(s.at(i));
            if (staLeftBrackets.size() != 0 && staLeftBrackets.top() == mpIter->second)
            {
                staLeftBrackets.pop();
                continue;
            }

            return false;
        }

        if (0 != ((int) staLeftBrackets.size()))
        {
            return false;
        }

        return true;
    }
};

int main()
{
    Solution solution;
    string str1 = "(";
    string str2 = "()[]{}";
    string str3 = "(]";
    string str4 = "([)]";
    string str5 = "{[]}";

    cout << str1 << endl;
    cout << solution.isValid(str1) << endl;
    cout << str2 << endl;
    cout << solution.isValid(str2) << endl;
    cout << str3 << endl;
    cout << solution.isValid(str3) << endl;
    cout << str4 << endl;
    cout << solution.isValid(str4) << endl;
    cout << str5 << endl;
    cout << solution.isValid(str5) << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        if(s == "")
        {
            return 0;
        }

        int res = 0;
        int pos = 0;
        int len = s.length();
        string tmpStr;
        map<string, int> mRomanInt = {{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}, 
                                      {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};
        map<string, int>::iterator iter = mRomanInt.begin();

        while(pos < len)
        {
            tmpStr = s.substr(pos, 2);
            iter = mRomanInt.find(tmpStr);
            if(iter != mRomanInt.end())
            {
                res += iter->second;
                pos += 2;
                continue;
            }
            
            tmpStr = s.substr(pos, 1);
            iter = mRomanInt.find(tmpStr);
            if(iter != mRomanInt.end())
            {
                res += iter->second;
                pos += 1;
                continue;
            }
            else 
            {
                break;
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.romanToInt("III") << endl;
    cout << solution.romanToInt("IV") << endl;
    cout << solution.romanToInt("IX") << endl;
    cout << solution.romanToInt("LVIII") << endl;
    cout << solution.romanToInt("MCMXCIV") << endl;

    return 0;
}
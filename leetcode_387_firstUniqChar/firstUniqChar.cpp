#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int strLen = s.length();
        unordered_map<char, int> charCnt;

        for (int i = 0; i < strLen; i++)
        {
            unordered_map<char, int> ::iterator iter = charCnt.find(s[i]);
            if (iter == charCnt.end())
            {
                charCnt.insert(pair<char, int>(s[i], 1));
            }
            else
            {
                iter->second = iter->second + 1;
            }
        }

        for (int i = 0; i < strLen; i++)
        {
            unordered_map<char, int> ::iterator iter = charCnt.find(s[i]);
            if (1 == iter->second)
            {
                return i;
            }
        } 

        return -1;
    }
};

int main ()
{
    Solution solu;
    cout << solu.firstUniqChar("leetcode") << endl;
    cout << solu.firstUniqChar("loveleetcode") << endl;
    cout << solu.firstUniqChar("aabb") << endl;
    return 0;
}
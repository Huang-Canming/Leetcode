#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int sLen = s.size(), tLen = t.size();
        unordered_map<char, int> alphaNumHash;
        unordered_map<char, int>::iterator iter;

        for (int i = 0; i < sLen; i++)
        {
            alphaNumHash[s[i]]++;
        }

        for (int i = 0; i < tLen; i++)
        {
            alphaNumHash[t[i]]--;
        }

        for (iter = alphaNumHash.begin(); iter != alphaNumHash.end(); iter++)
        {
            if (0 != iter->second)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution solution;
    string s = "rat";
    string t = "car";

    cout << solution.isAnagram(s, t) << endl;

    return 0;
}
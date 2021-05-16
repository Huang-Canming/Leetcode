#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (0 == (int) needle.size())
        {
            return 0;
        }

        int i = 0;
        int j = 0;

        for (i = 0; i < (int) haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                for (j = 1; j < (int) needle.size() && i + j < (int) haystack.size(); j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        break;
                    }
                }

                if (j == (int) needle.size())
                {
                    return i;
                }
            }
        }

        return -1;
    }
};

int main()
{
    string haystack1 = "hello";
    string needle1 = "ll";
    string haystack2 = "aaaaa";
    string needle2 = "bba";
    Solution solution;

    cout << solution.strStr(haystack1, needle1) << endl;
    cout << solution.strStr(haystack2, needle2) << endl;

    return 0;
}
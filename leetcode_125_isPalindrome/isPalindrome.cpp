#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int stringSize = s.size();
        int left = 0, right = stringSize - 1;

        if (0 == stringSize || 1 == stringSize)
        {
            return true;
        }

        while (left < right)
        {
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }

            if (!isalnum(s[right]))
            {
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right]))  
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }

        return true;
    }
};

int main()
{
    string s = "98";
    Solution solution;

    cout << solution.isPalindrome(s) << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int vecSize = s.size();

        for (int i = 0; i < vecSize / 2; i++)
        {
            tmp = s[i];
            s[i] = s[vecSize - i - 1];
            s[vecSize - i - 1] = tmp;
        }

        return;
    }
};

int main()
{
    vector<char> s1 = {'h','e','l','l','o'};
    vector<char> s2 = {'H','a','n','n','a','h'};
    Solution solu;

    solu.reverseString(s1);
    for (char element : s1)
    {
        cout << element << " ";
    }
    cout << endl;

    solu.reverseString(s2);
    for (char element : s2)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
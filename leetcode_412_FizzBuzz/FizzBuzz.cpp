#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            if (0 == i % 3 && 0 == i % 5)
            {
               res.push_back("FizzBuzz");
            }
            else if (0 == i % 3 && 0 != i % 5)
            {
                res.push_back("Fizz");
            }
            else if (0 != i % 3 && 0 == i % 5)
            {
                res.push_back("Buzz");
            }
            else
            {
                res.push_back(to_string(i));
            }
        }

        return res;
    }
};

int main()
{
    Solution solu;
    vector<string> res = solu.fizzBuzz(15);
    for (string str : res)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
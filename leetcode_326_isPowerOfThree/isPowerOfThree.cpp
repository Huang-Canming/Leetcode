#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {

        if (n < 1)
        {
            return false;
        }
        else if (1 == n)
        {
            return true;
        }

        while (n > 1)
        {
            if (0 == n % 3)
            {
                n = n / 3;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution solu;
    bool res = solu.isPowerOfThree(19684);
    cout << res << endl;
    return 0;
}
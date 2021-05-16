#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {

        int tmp = n, res = 0;
        long long factorial = 1;

        while (tmp >= 1)
        {
            factorial *= tmp;
            tmp--;
        }

        while (0 == factorial % 10)
        {
            factorial = factorial / 10;
            res++;
        }

        return res;
    }
};

int main()
{
    Solution solution;

    cout << solution.trailingZeroes(5) << endl;

    return 0;
}
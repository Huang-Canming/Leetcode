#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double subRes = 0;
        long long power = n;

        if (0 == power)
        {
            return 1.0;
        }

        if (power < 0)
        {
            power = -1 * power;
            x = 1 / x;
        }

        subRes = myPow(x, power / 2);

        return 0 == power % 2 ? subRes * subRes : subRes * subRes * x;
    }
};

int main()
{
    Solution solution;

    cout << solution.myPow(2.00000, 10) << endl;
    cout << solution.myPow(2.10000, 3) << endl;
    cout << solution.myPow(2.00000, -2) << endl;
    cout << solution.myPow(0.44894, -5) << endl;
    cout << solution.myPow(2.00000,-2147483648) << endl;

    return 0;
}
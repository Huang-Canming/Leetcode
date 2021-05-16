#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {

        int count = 0;

        while (0 != n)
        {
            if (1 == n % 2)
            {
                count++;
            }

            n = n / 2;
        }

        return count;
    }
};

int main()
{
    Solution solution;

    cout << solution.hammingWeight(3) << endl;

    return 0;
}
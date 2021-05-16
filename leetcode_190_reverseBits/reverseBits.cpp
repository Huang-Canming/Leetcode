#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, rank = 1;
        vector<int> vBit(32, 0);

        for (int i = 31; i >= 0; i--)
        {
            vBit[i] = n % 2;
            n = n / 2;
        }

        for (int i = 0; i < 32; i++)
        {
            res += vBit[i] * rank;
            rank = rank * 2;
        }

        return res;
    }
};

int main()
{
    Solution solution;

    cout << solution.reverseBits(43261596) << endl;

    return 0;
}
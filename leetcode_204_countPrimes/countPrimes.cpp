#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPrime(int n) {

        for (int i = 2; i * i <= n; i++)
        {
            if (0 == n % i)
            {
                return false;
            }
        }

        return true;
    }

    int countPrimes(int n) {

        int count = 0;

        /* 1 不是质数 */
        for (int i = 2; i < n; i++)
        {
            if (true == isPrime(i))
            {
                count++;
            }
        }

        return count;
    }

    int countPrimes_E(int n) {

        if (0 == n || 1 == n)
        {
            return 0;
        }

        int count = 0;
        vector<bool> primeTable(n, true);   // 0, 1，2,  ··· , n - 1

        /* 0、1不是素数，判断是否为素数从2开始 */
        for (int i = 2; i < n; i++)
        {
            if (false == primeTable[i])
            {
                continue;
            }

            if (true == isPrime(i))
            {
                count++;
                continue;
            }

            primeTable[i] = false;
            for (long long j = (long long) i * i; i * j <= n; j++)
            {
                primeTable[i * j] = false;
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;

    cout << solution.countPrimes_E(10) << endl;

    return 0;
}
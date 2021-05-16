#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == 0)
        {
            return 0;
        }

        if(divisor == 1) 
        {
            return dividend;
        }

        if(divisor == -1)
        {
            // 只要不是最小的那个整数，都是直接返回相反数就好啦，如果是最小的那个，那就返回最大的整数啦
            return dividend > INT_MIN ? -dividend : INT_MAX;
        }

        long longDividend = dividend;
        long longDivisor = divisor;
        long res = 0;
        int sign = 1; 

        if((longDividend > 0 && longDivisor < 0) || (longDividend < 0 && longDivisor > 0))
        {
            sign = -1;
        }

        longDividend = longDividend > 0 ? longDividend : -longDividend;
        longDivisor = longDivisor > 0 ? longDivisor : -longDivisor;
        res = div(longDividend, longDivisor);
        if(sign > 0)
        {
            return res > INT_MAX ? INT_MAX : res;
        }

        return -res;
    }

    int div(long longDividend, long longDivisor){

        if(longDividend < longDivisor)
        {
            return 0;
        }

        long count = 1;
        long tmp = longDivisor;             // 在后面的代码中不更新 longDivisor
        while((tmp + tmp) <= longDividend)
        {
            count = count + count;          // 最小解翻倍
            tmp = tmp + tmp;                // 当前测试的值也翻倍
        }

        return count + div(longDividend - tmp, longDivisor);
    }
};

int main()
{
    Solution solution;

    cout << solution.divide(-2147483648, -1) << endl;

    return 0;
}
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        if (0 == x)
        {
            return 0;
        }

        int res = 1;

        while (x >= pow(res, 2))
        {
            res++;
        }

        return (res - 1);
    }

    int mySqrt_binarySearch(int x) {

        int l = 0;
        int r = x;
        int mid = 0;

        while (l <= r)
        {
            mid = (l + r) / 2;
            if (x >= mid * mid)
            {
                l = mid + 1;
            }
            else 
            {
                r = mid - 1;
            }
        }

        return (mid - 1);
    }

};

int main()
{
    Solution solution;

    //cout << solution.mySqrt(4) << endl;
    //cout << solution.mySqrt(8) << endl;

    cout << solution.mySqrt_binarySearch(4) << endl;
    cout << solution.mySqrt_binarySearch(8) << endl;

    return 0;
}
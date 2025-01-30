#include <iostream>
#include <unordered_set>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> sum_record;

        while (true)
        {
            sum = 0;
            while (n > 0)
            {
                sum += pow((n % 10), 2);
                n = n / 10;
            }

            if (1 == sum)
            {
                return true;
            }
            else if (sum_record.end() != sum_record.find(sum))
            {
                return false;
            }
            else
            {
                sum_record.insert(sum);
                n = sum;
            }
        }
    }
};

int main()
{
    Solution solu;
    bool res = solu.isHappy(1999999999);
    cout << res << endl;
    return 0;
}
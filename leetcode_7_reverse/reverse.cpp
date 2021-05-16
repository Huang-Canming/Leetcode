#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        if(-10 < x && x < 10)
        {
            return x;
        }

        long res = 0;
        int rank = 0;
        stack<int> sta;

        while(x != 0)
        {
            sta.push(x % 10);
            x = x / 10;
        }

        while(sta.size() > 0)
        {
            res += sta.top() * pow(10, rank);
            sta.pop();
            rank++;
        }

        if(res >= (-1 * pow(2, 31)) && res <= (pow(2, 31) - 1))
        {
            return res;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    int x = 0;
    Solution solution;

    x = 123;
    cout << solution.reverse(x) << endl;

    x = -123;
    cout << solution.reverse(x) << endl;

    x = 120;
    cout << solution.reverse(x) << endl;

    x = 0;
    cout << solution.reverse(x) << endl;

    //cout << "test : " << ((-3) % 10) << endl;

    return 0;
}
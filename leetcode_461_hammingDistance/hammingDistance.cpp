#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x > 0 || y > 0) {
            if (x % 2 != y % 2) {
                res++;
            }
            x = x / 2;
            y = y / 2;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
    return 0;
}
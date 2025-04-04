#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // 某个整数对应二进制数的 1 的数量等于其右移一位的 1 的数量加上 0 或者 1
        // 说人话：
        // 最低位的 1 的个数 = n % 2
        // 最低位以上的 1 的个数 = n / 2 的 1 的个数
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            res[i] = res[i / 2] + i % 2;
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<int> res = s.countBits(5);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
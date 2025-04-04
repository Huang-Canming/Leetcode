#include <iostream>
#include <vector>

using namespace std;

/*
十进制整数  二进制表示
0           0
1           1
2           10
3           11
4           100
5           101
6           110
7           111
8           1000
9           1001
10          1010
11          1011
12          1100
13          1101
14          1110
15          1111
···         ···
*/

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
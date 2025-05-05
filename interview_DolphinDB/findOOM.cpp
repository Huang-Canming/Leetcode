#include <iostream>
#include <algorithm>

using namespace std;

// 计算前 t 秒总共需要分配的内存
long long totalMemory(long long t) {
    return t * (t + 1) / 2;
}
void findOOM(long long M1, long long M2, long long &t, long long &m1, long long &m2) {
    // 题目要求时间复杂度不超过 log(M1+M2)，通过二分查找确定 t
    // M1、M2 最大为 10^18，第 t 秒申请的总内存为 t*(t+1)/2。2e9 * (2e9 + 1) / 2 大于 10^18，所以 t 肯定小于 2e9
    long long left = 1, mid, right = 2e9;
    while (left < right) {
        mid = (left + right) / 2;
        if (totalMemory(mid) > M1 + M2) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    t = left - 1;

    // 模拟前 t 秒的内存分配
    m1 = M1;
    m2 = M2;
    for (long long i = 1; i <= t; ++i) {
        if (m1 >= m2) {
            m1 -= i;
        } else {
            m2 -= i;
        }
    }

    t = t + 1;
    return;
}

int main() {
    long long M1 = 2, M2 = 2, t = 0, m1 = 0, m2 = 0;
    findOOM(M1, M2, t, m1, m2);
    cout << t << " " << m1 << " " << m2 << endl;
    return 0;
}
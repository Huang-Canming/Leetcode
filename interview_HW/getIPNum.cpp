#include <iostream>
#include <string>

using namespace std;

int getIPNum (string s) {
    int res = 0, cnt = 0, zeroNum = 0, oneNum = 0, twoNum = 0, fiveNum = 0, underFiveNum = 0, strLen = s.length();

    for (char c : s) {
        if ('0' == c) {
            zeroNum++;
        } else if ('1' == c) {
            oneNum++;
        } else if ('2' == c) {
            twoNum++;
        } else if ('5' == c) {
            fiveNum++;
        }

        if (c < '5') {
            underFiveNum++;
        }
    }

    // 一位 IP
    cnt += strLen;

    // 两位 IP，排除开头为 0 的情况
    cnt += strLen * strLen;
    if (zeroNum > 0) {
        cnt -= strLen;
    }

    // 三位 IP
    if (oneNum > 0) {
        // 1XX
        cnt += strLen * strLen;
    }
    if (twoNum > 0) {
        // 2 (0~4) X
        cnt += underFiveNum * strLen;
        // 25 (0~4)
        if (fiveNum > 0) {
            cnt += underFiveNum;
        }
    }

    res = cnt * cnt * cnt * cnt;
    return res;
}

int main () {
    string str = "25";
    cout << getIPNum(str) << endl;
    return 0;
}
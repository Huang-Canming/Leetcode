#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getSubMinDist(string word1, string word2, int m, int n, vector<vector<int>> &subMinDist) {
        int subMin = max(m, n);
        
        if (0 == m || 0 == n) {
            // 返回非零值（m、n 有一个非零）或者返回 0（m、n 都是零）
            return m >= n ? m : n;
        } else if (-1 != subMinDist[m - 1][n - 1]) {
            // 返回曾经记录的中间结果
            return subMinDist[m - 1][n - 1];
        }
        
        if (word1[m - 1] == word2[n - 1]) {
            // word1 的第 m 个字符和 word2 的第 n 个字符是否相等
            subMin = getSubMinDist(word1, word2, m - 1, n - 1, subMinDist);
        }

        int modOptDist = getSubMinDist(word1, word2, m - 1, n - 1, subMinDist) + 1;
        subMin = min(subMin, modOptDist);
        
        int addOptDist = getSubMinDist(word1, word2, m, n - 1, subMinDist) + 1;
        subMin = min(subMin, addOptDist);
        
        int delOptDist = getSubMinDist(word1, word2, m - 1, n, subMinDist) + 1;
        subMin = min(subMin, delOptDist);
        
        subMinDist[m - 1][n - 1] = subMin;
        return subMin;
    }


    int minDistance(string word1, string word2) { 
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> subMinDist(m, vector<int>(n, -1));
        
        // 判断 word1 的前 m 个字符转换到 word2 的前 n 个字符需要的最小距离
        int minDist = getSubMinDist(word1, word2, m, n, subMinDist);
        
        return minDist;
    }
};


int main() {
    Solution s;
    string word1 = "horse";
    string word2 = "ros";
    cout << s.minDistance(word1, word2) << endl;

    string word3 = "intention";
    string word4 = "execution";
    cout << s.minDistance(word3, word4) << endl;

    string word5 = "mart";
    string word6 = "karma";
    cout << s.minDistance(word5, word6) << endl;

    return 0;
}
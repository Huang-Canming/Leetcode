#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        for (char ch: tasks){
            hash[ch]++;
        }
        int m = 0, x = 0;
        for (auto pair: hash){
            if (m < pair.second){
                m = pair.second;
                x = 1;
            }
            else if (pair.second == m){
                x++;
            }
        }
        int num1 = tasks.size();
        int num2 = (m-1)*(n+1)+x;
        return max(num1, num2);
    }
};

int main () {
    Solution sol;
    string tasks = "AAABBB";
    vector<char> vec(tasks.begin(), tasks.end());
    cout << sol.leastInterval(vec, 2) << endl;
    return 0;
}


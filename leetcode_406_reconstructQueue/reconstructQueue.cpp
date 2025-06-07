#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[0] != b[0]) {
        return a[0] > b[0];     // 第一个元素不同，按元素值降序排序
    } else {
        return a[1] < b[1];     // 第一个元素相同，k 值大的在后面
    }
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> res;
        for (vector<int> person : people) {
            if (person[1] > res.size()) {
                res.push_back(person);
            } else {
                res.insert(res.begin() + person[1], person);
            }
        }

        return res;
    }
};

int main () {
    Solution solu;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> res = solu.reconstructQueue(people);

    for (vector<int> person : res) {
        cout << person[0] << ", " << person[1] << endl;
    }

    return 0;
}
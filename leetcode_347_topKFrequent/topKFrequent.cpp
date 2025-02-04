#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
private:
    struct numCmp
    {
        bool operator ()(pair<int, int> &m, pair<int, int> &n) {
            if (m.second < n.second) {
                return true;
            } else {
                return false;
            }
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> numCnt;
        priority_queue<pair<int, int>, vector<pair<int, int>>, numCmp> numQue;

        for (int num : nums) {
            numCnt[num]++;
        }

        for (auto elem : numCnt) {
            numQue.push(elem);
        }

        int tmp = 0;
        while (tmp < k && !numQue.empty()) {
            res.push_back(numQue.top().first);
            numQue.pop();
            tmp++;
        }

        return res;
    }
};

void printRes(vector<int> &res){
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    return;
}

int main () {
    Solution solu;

    vector<int> nums1 = {1,1,1,2,2,3};
    int k1 = 2;
    vector<int> res1 = solu.topKFrequent(nums1, k1);
    printRes(res1);

    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> res2 = solu.topKFrequent(nums2, k2);
    printRes(res2);
    
    return 0;
}
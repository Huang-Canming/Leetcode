#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int lastElem = 0, intervalsSize = (int)intervals.size();
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervalsSize; i++)
        {
            if (res[lastElem][1] >= intervals[i][0])
            {
                res[lastElem][1] = max(res[lastElem][1], intervals[i][1]); 
            }
            else
            {
                res.push_back({intervals[i][0], intervals[i][1]});
                lastElem++;
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};

    solution.merge(intervals1);
    solution.merge(intervals2);

    return 0;
}
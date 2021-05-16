#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool cmp(const string &a, const string &b)
    {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int> &nums)
    {
        string strRes = "";
        vector<string> vecStrNums;
        
        for (auto num : nums) {
            vecStrNums.push_back(to_string(num));
        }

        sort(vecStrNums.begin(), vecStrNums.end(), cmp);
        
        if ("0" == vecStrNums[0]){
            return "0";
        }

        for (auto strNum : vecStrNums) {
            strRes += strNum;
        }
        return strRes;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {10, 2};
    vector<int> nums2 = {3, 30, 34, 5, 9};
    vector<int> nums3 = {1};
    vector<int> nums4 = {10};

    cout << solution.largestNumber(nums1) << endl;
    cout << solution.largestNumber(nums2) << endl;
    cout << solution.largestNumber(nums3) << endl;
    cout << solution.largestNumber(nums4) << endl;

    return 0;
}
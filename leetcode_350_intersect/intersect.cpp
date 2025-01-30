#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        vector<int> res;

        for (int i = 0; i < nums1_size; i++)
        {
            int num1 = nums1[i];
            int num1_cnt = 0;
            for (int j = 0; j < i; j++)
            {
                if (num1 == nums1[j])
                {
                    num1_cnt++;
                }
            }

            int num2_cnt = 0;
            for (int j = 0; j < nums2_size; j++)
            {
                if (num1 == nums2[j])
                {
                    num2_cnt++;
                    if (num2_cnt > num1_cnt)
                    {
                        res.push_back(num1);
                        break;
                    }
                }
            }
        }

        return res;
    }
};

int main ()
{
    Solution solu;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    
    vector<int> res = solu.intersect(nums1, nums2);
    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;
}
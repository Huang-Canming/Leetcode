#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int index1 = 0;
        int index2 = 0;
        int index1_copy = 0;

        vector<int> nums1_copy;
        nums1_copy.assign(nums1.begin(), nums1.begin() + m);

        for (index1 = 0, index2 = 0, index1_copy = 0; index1 < (m + n); index1++)
        {
            if (index2 >= n || (index1_copy < m && nums1_copy[index1_copy] <= nums2[index2]))
            {
                nums1[index1] = nums1_copy[index1_copy];
                index1_copy++;
            }
            else if (index1_copy >= m || (index2 < n && nums1_copy[index1_copy] > nums2[index2]))
            {
                nums1[index1] = nums2[index2];
                index2++;
            }
        }

        return;
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (m == 0)
        {
            nums1.assign(nums2.begin(), nums2.end());
            return;
        }
        else if (n == 0)
        {
            return;
        }
        
        for (int index1 = m - 1, index2 = n - 1, index3 = m + n - 1; index3 >= 0; index3--)
        {
            if (index2 < 0 || (index1 >= 0 && nums1[index1] >= nums2[index2]))
            {
                nums1[index3] = nums1[index1];
                index1--;
            }
            else if (index1 < 0 || (index2 >= 0 && nums1[index1] < nums2[index2]))
            {
                nums1[index3] = nums2[index2];
                index2--;
            }
        }

        return;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    int m = 1, n = 1;

    solution.merge2(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }

    return 0;
}
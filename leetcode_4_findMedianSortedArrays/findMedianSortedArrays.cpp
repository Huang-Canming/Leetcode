#include <iostream>
#include <vector>

using namespace std;

#if 0
// 时间复杂度 O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = 0, idx2 = 0, m = nums1.size(), n = nums2.size();
        int mergeIdx = 0, mergeNum = 0, leftNum = 0, rightNum = 0;
		double midNum = 0.0;
		
		while (idx1 < m || idx2 < n) {
			if (idx1 >= m) {
				mergeNum = nums2[idx2++];
			} else if (idx2 >= n) {
				mergeNum = nums1[idx1++];
			} else {
				if (nums1[idx1] <= nums2[idx2]) {
					mergeNum = nums1[idx1++];
				} else {
					mergeNum = nums2[idx2++];
				}
			}
			mergeIdx++;
			
			if (0 == (m + n) % 2) {
				// m+n 共偶数个，中位数下标是 (m+n)/2 和 (m+n)/2+1，求平均值
				if (mergeIdx == (m+n) / 2) {
					leftNum = mergeNum;
				} else if (mergeIdx == (m+n) / 2 + 1) {
					rightNum = mergeNum;
					midNum = ((double)leftNum + (double)rightNum) / 2;
					break;
				}
			} else {
				// m+n 共奇数个，中位数下标 (m+n)/2+1
				if (mergeIdx == (m + n) / 2 + 1) {
					midNum = (double)mergeNum;
					break;
				}
			}
		}
		
		return midNum;
    }
};
#else
// 时间复杂度 O(log(m+n))
class Solution {
public:
    /*  官解 二分查找法：
        这道题可以转化成寻找两个有序数组中的第 k 小的数，其中 k 为 (m+n)/2 或 (m+n)/2+1
        假设两个有序数组分别是 A 和 B。要找到第 k 个元素，我们可以比较 A[k/2−1] 和 B[k/2−1]，其中 / 表示整数除法。
        由于 A[k/2−1] 和 B[k/2−1] 的前面分别有 k/2−1 个元素
        所以对于 A[k/2−1] 和 B[k/2−1] 中的较小值，最多只会有 (k/2−1)+(k/2−1) 个（不超过 k−2 个）元素比它小，那么它就不能是第 k 小的数了。
        可以归纳出三种情况：
        1、如果 A[k/2−1]<B[k/2−1]，则比 A[k/2−1] 小的数最多只有 A 的前 k/2−1 个数和 B 的前 k/2−1 个数，即比 A[k/2−1] 小的数最多只有 k−2 个
           因此 A[k/2−1] 不可能是第 k 个数，A[0] 到 A[k/2−1] 也都不可能是第 k 个数，可以全部排除。
        2、如果 A[k/2−1]>B[k/2−1]，则可以排除 B[0] 到 B[k/2−1]。
        3、如果 A[k/2−1]=B[k/2−1]，则可以归入第一种情况处理。
        可以看到，比较 A[k/2−1] 和 B[k/2−1] 之后，可以排除 k/2 个不可能是第 k 小的数，查找范围缩小了一半。
        同时，我们将在排除后的新数组上继续进行二分查找，并且根据我们排除数的个数，减少 k 的值。
        有以下三种情况需要特殊处理：
        1、如果 A[k/2−1] 或者 B[k/2−1] 越界，那么我们可以选取对应数组中的最后一个元素。
           在这种情况下，我们必须根据排除数的个数减少 k 的值，而不能直接将 k 减去 k/2。
        2、如果一个数组为空，说明该数组中的所有元素都被排除，我们可以直接返回另一个数组中第 k 小的元素。
        3、如果 k=1，我们只要返回两个数组首元素的最小值即可。
    */
    int findKthNum (vector<int>& nums1, int m, vector<int>& nums2, int n, bool even, int k) {
        int KthNum = 0, pivot1 = 0, pivot2 = 0;

        while (m > 0 && n > 0 && k > 1) {
            int excludeNum = min(k / 2, min(m, n));
            // find Kth num
            if (nums1[pivot1 + excludeNum - 1] <= nums2[pivot2 + excludeNum - 1]) {
                m -= excludeNum;         // 排除掉 nums1 的前 k/2 个数
                pivot1 += excludeNum;
            } else {
                n -= excludeNum;         // 排除掉 nums2 的前 k/2 个数
                pivot2 += excludeNum;
            }
            k -= excludeNum;
        }

        if (0 == m) {
            KthNum = nums2[pivot2 + k - 1];
        } else if (0 == n) {
            KthNum = nums1[pivot1 + k - 1];
        } else {
            if (nums1[pivot1] <= nums2[pivot2]) {
                KthNum = nums1[pivot1];
            } else {
                KthNum = nums2[pivot2];
            }
        }
        return KthNum;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
		double midNum = 0.0;

        if (0 == (m + n) % 2) {
            // m+n 共偶数个，中位数下标是 (m+n)/2 和 (m+n)/2+1，求平均值
            int leftNum = findKthNum(nums1, m, nums2, n, true, (m+n) / 2);
            int rightNum = findKthNum(nums1, m, nums2, n, true, ((m+n) / 2 + 1));
            midNum = ((double)leftNum + (double)rightNum) / 2.0;
        } else {
            // m+n 共奇数个，中位数下标 (m+n)/2+1
            midNum = findKthNum(nums1, m, nums2, n, false, ((m+n) / 2 + 1));
        }
        return midNum;
    }
};
#endif

int main () {
    Solution sol;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << sol.findMedianSortedArrays(nums3, nums4) << endl;

    vector<int> nums5 = {1,2,3,4,5};
    vector<int> nums6 = {6,7,8,9,10,11,12,13,14,15,16,17};
    cout << sol.findMedianSortedArrays(nums5, nums6) << endl;
    return 0;   
}
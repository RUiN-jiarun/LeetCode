/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
			vector<int> num = nums1;
			nums1 = nums2;
			nums2 = num;
		}
		// Make sure that nums1 smaller than nums2
		int m = nums1.size();
		int n = nums2.size();

		int totalleft = (m + n + 1) / 2;        // the left part of the merged list
		int left = 0;                           // pointer to the beginning of nums1
		int right = m;                          // pointer to the end of nums1
		while (left < right) {                  
			int i = left + (right - left + 1) / 2;
			int j = totalleft - i;
			if (nums1[i - 1] > nums2[j]) {
				right = i - 1;
			}
			else {
				left = i;
			}
		}
		int i = left;
		int j = totalleft - i;
		int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
		int nums_i = (i == m ? INT_MAX : nums1[i]);
		int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
		int nums_j = (j == n ? INT_MAX : nums2[j]);
		
		if ((m + n) % 2 == 1) {
			return max(nums_im1, nums_jm1);
		}
		else
			return (double)(max(nums_im1, nums_jm1) + min(nums_i, nums_j)) / 2.0;

    }
};
// @lc code=end


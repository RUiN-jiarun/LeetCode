/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mid_min = nums[nums.size() - 1];
        int mid_max = nums[0];
        int start = 0, end = -1;
        for (int i = 0; i < nums.size(); i++) {
            // 从左到右维护最大值，找到右边界
            if (nums[i] < mid_max) {
                end = i;
            } else {
                mid_max = nums[i];
            }

            if (nums[nums.size() - 1 - i] > mid_min) {
                start = nums.size() - 1 - i;
            } else {
                mid_min = nums[nums.size() - 1 - i];
            }
        }
        return end - start + 1;
    }
};
// @lc code=end


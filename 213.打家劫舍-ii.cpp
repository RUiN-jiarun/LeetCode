/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob1(vector<int>& nums, int start, int end) {
        // 打家劫舍1：线性动态规划
        if (start == end) {
            return nums[start];
        }
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        // 有环的动态规划问题，首尾两个也相当于是相邻的房屋
        // 我们考虑两种情况
        // 1，偷第一间屋子，那么就不能偷最后一间。
        // 2，不偷第一间屋子，那么剩下的都无所谓，和打家劫舍1是一样的逻辑。
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1) 
            return nums[0];
        return max(rob1(nums, 0, nums.size() - 2), rob1(nums, 1, nums.size() - 1));
    }
};
// @lc code=end


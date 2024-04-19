/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray_dp(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        // dp[i]表示以nums[i]结尾的最大子数组和
        int maxVal = INT_MIN;
        // 初始情况：数组只有一个数
        dp[0] = nums[0];
        maxVal = dp[0];
        // 开始考虑增加的情况
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i];
            // 取区间累计最大值
            if (cnt > maxVal) {
                maxVal = cnt;
            }
            // 如果和为负数，一定降低了总和，重置最大子序列起始位置
            if (cnt <= 0) {
                cnt = 0;
            }
        }
        return maxVal;
    }
};
// @lc code=end


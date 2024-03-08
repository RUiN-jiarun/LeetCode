/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // 对比300题，突出一个连续
        vector<int> dp(nums.size() + 1, 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 如果用动态规划
        if (nums.size() == 0)   return 0;
        vector<int> dp(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            // 注意要遍历所有的之前的数，因为可能不连续
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        // 最后要返回最大的值
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end


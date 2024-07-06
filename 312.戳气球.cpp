/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        // 状态转移，i从下往上，j从左往右
        for (int i = n; i >= 0; i--) {
            for (int j = i + 1; j < n + 2; j++) {
                // 最后戳破的气球是谁？
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i]*nums[j]*nums[k]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
// @lc code=end


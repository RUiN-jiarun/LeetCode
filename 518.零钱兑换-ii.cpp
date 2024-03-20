/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 完全背包问题
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // 外层是物品，内层是背包容量，从前向后
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end


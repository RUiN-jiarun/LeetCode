/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i]代表到达第i个台阶所需要花费的最小费用
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // 最后一步：不用花费，所以取倒数第一步和倒数第二步的最小
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);

    }
};
// @lc code=end


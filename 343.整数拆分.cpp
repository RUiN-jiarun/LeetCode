/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        // 只从2开始初始化，意味着拆分数字2得到的最大乘积是1
        dp[2] = 1;
        // 必须从前向后遍历，i从3开始，j从1开始，这样dp[i - j] = dp[3 - 1] = dp[2]即边界条件
        // 每次有两种可能：不拆或者拆
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
// @lc code=end


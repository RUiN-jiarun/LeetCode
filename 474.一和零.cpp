/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j]代表最多有i个0和j个1的strs的最大子集的元素数量
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto& str: strs) {
            int ones = 0, zeros = 0;
            for (char c : str) {
                if (c == '0')   zeros++;
                else            ones++;
            }
            // 保证物品只被放入背包一次，所以必须倒序遍历
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // dp[i][j]: s的第i个字符和p的前j个字符匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // 初始化：主要考虑空字符串的匹配情况
        dp[0][0] = true;
        // 对于空字符串和*，是可以匹配的
        for (int i = 1; i <= n; i++) {
            if (dp[0][i - 1] && p[i - 1] == '*') {
                dp[0][i] = true;
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 两个字符相等，则根据前一个状态转移
                // p的字符为？，则可以匹配，根据前一个状态转移
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // p的字符为*，情况比较复杂
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end


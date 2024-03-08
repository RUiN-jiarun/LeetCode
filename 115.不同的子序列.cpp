/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        // 只考虑删除操作，使得s变成若干个t
        // dp[i][j]为以s[i-1]结尾的序列中，以t[j-1]结尾的子序列个数
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        // 初始化
        // dp[i][0]指的是以s[i-1]结尾的序列中，删除若干字符变成后出现的空字符串的个数
        // dp[i][0] = 1，即删除所有元素，就一种
        // dp[0][j]指的是从空字符串中删出一个t[j-1]，肯定为0
        // dp[0][0] = 1
        for (int i = 0; i <= s.size(); i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= t.size(); j++) {
            dp[0][j] = 0;
        }
        // 递推
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    // 如果相等，考虑两种情况
                    // 用s[i-1]匹配t，则dp[i][j] = dp[i-1][j-1]
                    // 不用s[i-1]匹配t，则dp[i][j] = dp[i-1][j]
                    // 如：s = "bagg", t = "bag", 考虑s[3]和t[2]？
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 不要求连续，但是要符合相对顺序
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        // dp[i][j]是text1[i-1]和text2[j-1]为末尾的最长公共子序列
        // 这样定义的好处是dp[i][0]和dp[0][j]都是0，无意义
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // 两个字符相等，则直接+1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 否则，有两种可能——变i或者变j
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
// @lc code=end


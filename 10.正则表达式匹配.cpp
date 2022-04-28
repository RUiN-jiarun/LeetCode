/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        // 这道题用递归都可以做，也很好想
        // 学习动态规划问题的思路
        const int m = s.length();
        int n = p.length();
        // dp[a][b]表示s[a:]和p[b:]可以匹配
        bool dp[20][30] = {};
        dp[m][n] = true;
        for (int i = m; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                // 先检测第一个字符能否匹配。因为*前面必须有有效字符
                bool first_match = i < m && (p[j] == s[i] || p[j] == '.');
                // 情况1：*将前一字符重复了0次，等于说是无效的重复，那么first_match=false
                // 如：s=aab p=c*a*b
                // 情况2：s中第一个字符已经匹配，留下p的第一个字符从s的下一个字符开始匹配
                // 如：s=aaa p=a*
                if (j + 1 < n && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } 
                // 情况3：没有*，继续检测
                else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 用双指针肯定可以
        // 考虑DP
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 如果不相等的情况，其实不用增加dp[i][j]
                    // 也就是s[i - 1]当前并没有出现在t中
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        if (dp[s.size()][t.size()] == s.size())
            return true;
        else 
            return false;
    }
};
// @lc code=end


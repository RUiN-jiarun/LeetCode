/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j]代表s[i:j]内的字串是否为回文的
        int res = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // 递推
        // 画个表就知道了，这道题注意遍历循环的方向
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    // a aa cabac
                    if (j - i <= 1 || dp[i + 1][j - 1]) {
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=3084 lang=cpp
 *
 * [3084] 统计以给定字符开头和结尾的子字符串总数
 */

// @lc code=start
class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n = s.size();
        unordered_map<char, int> mp;
        vector<long long> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == c){
                dp[i + 1] = dp[i] + mp[c] + 1;
                mp[c]++;
            }
            else 
                dp[i + 1] = dp[i];

        }
        return dp[n];
    }
};
// @lc code=end


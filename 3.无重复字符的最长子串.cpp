/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding window algorithm
        int size=s.length();
        int j = 0;
        int res = 0;
        for (int i = 0; i < s.length() ;i++) {
            for (int k = j; k < i; k++) {
                if (s[i] == s[k]) {
                    j = k+1;
                    break;
                }
            }
            res = max(res, i-j+1);
 
        }
        return res;
    }
};
// @lc code=end


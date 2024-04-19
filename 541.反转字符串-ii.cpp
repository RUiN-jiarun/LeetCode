/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        // 每次加2 * k，这样就可以判断是否有需要反转的区间
        for (int i = 0; i < s.size(); i+=(2*k)) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            // 剩余小于k个，全部反转
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};
// @lc code=end


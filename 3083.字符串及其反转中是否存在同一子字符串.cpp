/*
 * @lc app=leetcode.cn id=3083 lang=cpp
 *
 * [3083] 字符串及其反转中是否存在同一子字符串
 */

// @lc code=start
class Solution {
public:
    bool isSubstringPresent(string s) {
        bool dic[26][26] {};
        for (int i = 1; i < s.length(); i++) {
            int x = s[i - 1] - 'a', y = s[i] - 'a';
            dic[x][y] = true;
            if (dic[y][x]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end


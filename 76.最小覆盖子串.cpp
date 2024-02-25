/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        string res = s;
        unordered_map<char, int> map_t, map_s;
        // 统计t中词频
        for (auto c : t) {
            map_t[c]++;
        }
        int i = 0, j = 0;
        bool flag = false;
        int valid = 0;  // 有效计数
        for (j = 0; j < s.size(); j++) {
            map_s[s[j]]++;
            // 该字符在窗口内出现次数小于t中个数，有效
            if (map_t[s[j]] >= map_s[s[j]]) {
                valid++;
            }
            // 反之，需要缩小窗口，同时改变计数
            while (map_s[s[i]] > map_t[s[i]]) {
                --map_s[s[i++]];
            }
            if (valid == t.size()) {
                flag = true;
                if (j - i + 1 < res.size()) {
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        if (!flag) {
            return "";
        } else {
            return res;
        }
    }
};
// @lc code=end


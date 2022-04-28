/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dic = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (dic[s[i]] < dic[s[i+1]])
                res -= dic[s[i]];
            else    
                res += dic[s[i]];
        }
        return res;
    }
};
// @lc code=end


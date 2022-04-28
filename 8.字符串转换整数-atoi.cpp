/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int i = 0;
        int flag = 1;
        // 读入字符串并丢弃无用的前导空格
        while(s[i] == ' ') {
            i++;
        }
        // 检查正负号
        if (s[i] == '-') {
            flag = -1;
            i++;
        } else if (s[i] == '+') {
            flag = 1;
            i++;
        }
        // 开始读数，确保是有效字符（数字）
        // 注意前导零和越界问题
        // 两种情况可能溢出：乘10的时候和累加当前数字的时候
        while (i < s.size() && s[i] <= '9' && s[i] >= '0' ){
            int digit = s[i] - '0';
            if (res > INT_MAX / 10) {
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            if (res == INT_MAX / 10 && flag > 0 && digit >= INT_MAX % 10) {
                return INT_MAX;
            }
            if (res == INT_MAX / 10 && flag < 0 && digit >= flag * (INT_MIN % 10)) {
                return INT_MIN;
            }
            res = 10 * res + digit;
            i += 1;
        }
        return res * flag;
    }
};
// @lc code=end


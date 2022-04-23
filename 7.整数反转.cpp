/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            res = x % 10 + res * 10;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        else   
            return res;
    }
};
// @lc code=end


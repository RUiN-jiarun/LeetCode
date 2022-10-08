/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 朴素思路：被除数不断减去除数，直到结果小于除数
        // 进阶优化：移位？
        if (dividend == 0 || divisor == 1)  return dividend;
        if (divisor == -1 && dividend == INT_MIN)  return INT_MAX;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long x = (dividend < 0) ? -(long)dividend : (long)dividend;
        long y = (divisor < 0) ? -(long)divisor : (long)divisor;
        long res = 0; 
        while (x >= y) {
            long tmp = y, mid = 1;
            while (x >= (tmp << 1)) {
                mid <<= 1;
                tmp <<= 1;
            }
            res += mid;
            x -= tmp;
        }
        return sign > 0 ? res : -res;
    }
};
// @lc code=end


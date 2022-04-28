/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        long res = 0;
        long tmp = x;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res == tmp)   return true;
        else return false;
    }
};
// @lc code=end


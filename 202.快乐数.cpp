/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int squareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int bit = n % 10;
            sum += bit * bit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(fast);
            fast = squareSum(fast);
        } while (slow != fast);
        return slow == 1;
    }
};
// @lc code=end


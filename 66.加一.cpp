/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i]) {
                return digits;
            }
        }
        digits = vector<int>(len + 1);
        digits[0] = 1;
        return digits;
    }
};
// @lc code=end


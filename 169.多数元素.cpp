/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int votes = 0;
        for (int n : nums) {
            if (votes == 0) candidate = n;
            if (n == candidate) votes++;
            if (n != candidate) votes--;
        }
        return candidate;
    }
};
// @lc code=end


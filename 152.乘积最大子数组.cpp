/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max_pos(nums), min_neg(nums);
        for (int i = 1; i < nums.size(); i++) {
            max_pos[i] = max(max_pos[i-1]*nums[i], max(nums[i], min_neg[i-1]*nums[i]));
            min_neg[i] = min(min_neg[i-1]*nums[i], min(nums[i], max_pos[i-1]*nums[i]));
        }
        return *max_element(max_pos.begin(), max_pos.end());
    }
};
// @lc code=end


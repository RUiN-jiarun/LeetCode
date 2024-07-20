/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (auto num : nums) {
            if (len < 2 || nums[len - 2] != num) {
                nums[len++] = num;
            }
        }
        return len;

    }
};
// @lc code=end


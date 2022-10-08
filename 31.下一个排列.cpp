/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 找到下一个大一点的排列，改变尽量小
        // 因为只能用额外的常数空间，因此不能直接开新数组排序
        int n = nums.size();
        // [4, 5, 2, 6, 3, 1]
        // [4, 5, 3, 6, 2, 1]
        // [4, 5, 3, 1 ,2 ,6]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;
        while (j <= k) {
            if (nums[j] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[j] == 1)
                j++;
            else if (nums[j] == 2)
                swap(nums[j], nums[k--]);
        }
    }
    void swap(int& a, int& b) {
        int t = b;
        b = a;
        a = t;
    }
};
// @lc code=end


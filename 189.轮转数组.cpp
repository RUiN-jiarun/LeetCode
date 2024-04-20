/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // 对k取模
        
        // 分别设置left和right指针
        int left = 0;
        int right = n - k - 1;
        
        // 交换前n-k个元素和后k个元素
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        
        // 分别设置left和right指针
        left = n - k;
        right = n - 1;
        
        // 交换剩余的元素
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        
        // 整体翻转数组
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end


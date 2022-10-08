/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 二分搜索问题
        // 旋转的意义：从旋转的下标处，后面的移到前面
        // 为什么要二分搜索？ O(log n)
        int n = nums.size();
        if (n == 1)     return nums[0] == target ? 0 : -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && nums[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && nums[n - 1] >= target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end


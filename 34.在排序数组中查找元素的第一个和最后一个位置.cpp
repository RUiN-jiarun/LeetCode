/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int idx = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                idx = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        if (idx == -1) {
            return vector<int>{-1, -1};
        } else {
            int idx1 = idx, idx2 = idx;
            for (int i = idx1; i >= 0 && nums[i] == target; i--) {
                idx1 = i;
            }
            for (int i = idx2; i < n && nums[i] == target; i++) {
                idx2 = i;
            }
            return vector<int>{idx1, idx2};
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int min_diff = 1e8;         // 用来更新差值

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i -1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return target;
                }
                // update
                if (abs(sum - target) < abs(min_diff - target)) {
                    min_diff = sum;
                }
                // move
                if (left > i + 1 && nums[left] == nums[left - 1] || sum < target) {
                    left++;
                }
                else if (right < nums.size() - 1 && nums[right] == nums[right + 1] || sum > target) {
                    right--;
                }
            }
        }
        return min_diff;
    }
};
// @lc code=end


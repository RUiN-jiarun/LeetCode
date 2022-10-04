/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 在朴素的想法中，必须要进行三重循环
        // 考虑如何减少循环开销
        // 由于目标是和为0，所以考虑正负相加的情况
        // 排序 + 定一议二 + 左右双指针
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0) 
            return ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)    break;
            if (i > 0 && nums[i] == nums[i -1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            int sum_target = 0 - nums[i];

            while (left < right) {
                if (nums[left] > sum_target)    break;
                if (left > i + 1 && nums[left] == nums[left - 1] || nums[left] + nums[right] < sum_target)
                    left++;
                else if (right < nums.size() - 1 && nums[right] == nums[right + 1] || nums[left] + nums[right] > sum_target)
                    right--;
                else {
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[left]);
                    res.push_back(nums[right]);
                    ans.push_back(res);
                    left++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


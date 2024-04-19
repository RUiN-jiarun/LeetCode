/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> results;
    vector<int> path;
    void backtracking(vector<int>& nums, int start) {
        results.push_back(path);    // 收集子集，不要漏掉自己
        if (start >= nums.size()) {
            return;                 // 终止条件
        }
        for (int i = start; i < nums.size(); i++) {
            // 去重
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtracking(nums, 0);
        return results;
    }
};
// @lc code=end


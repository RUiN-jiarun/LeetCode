/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        results.clear();
        path.clear();
        backtracking(nums, 0);
        return results;
    }
};
// @lc code=end


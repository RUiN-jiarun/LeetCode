/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, cur, res);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 10 && nums[i] >= -10) {
                int tmp = nums[i];
                cur.push_back(nums[i]);
                nums[i] = 11;       // 一个标记，用于剪枝
                dfs(nums, cur, res);
                nums[i] = tmp;      // 恢复
                cur.pop_back();
            }
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(ans, candidates, cur, 0, target);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& cur, int idx, int target) {
        if (target == 0) {
            ans.push_back(cur);
        }
        else if (target < 0) {
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            dfs(ans, candidates, cur, i, target - candidates[i]);
            cur.pop_back();
        }
    }
};
// @lc code=end


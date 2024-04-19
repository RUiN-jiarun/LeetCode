/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    // 相较于找所有组合，本题多了一个条件：要求找到和为n的k个数的组合
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int targetSum, int k, int sum, int start) {
        // 可以剪枝
        if (sum > targetSum) {
            return;
        }
        if (path.size() == k) {
            if (sum == targetSum) {
                res.push_back(path);
            } else {
                return;
            }
        }
        for (int i = start; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        path.clear();
        backtracking(n, k, 0, 1);
        return res;

    }
};
// @lc code=end


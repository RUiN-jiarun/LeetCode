/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            res.push_back(path);
        }
        // 去重：不能用排序和startIndex，所以要用set
        // 每次回溯，我们都用一个新的set，只用来记录本层元素是否重复使用
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            // 去重逻辑
            // 以及排除所取元素小于子序列最后一个元素的情况
            if ((!path.empty() && nums[i] < path.back()) 
                    || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);   // 记录这个元素在本层用过了，本层后面不能用了
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end


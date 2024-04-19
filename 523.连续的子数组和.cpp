/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(nums.begin(), nums.end());

        unordered_set<int> mp;
        mp.insert(0);

        for (int i = 1; i < n; i++) {
            pre[i] += pre[i - 1];
            if (mp.count(pre[i] % k) > 0) {
                return true;
            }
            mp.insert(pre[i - 1] % k);
        }

        return false;

    }
};
// @lc code=end


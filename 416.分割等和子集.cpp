/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 0-1背包问题
        // 背包容积为sum/2
        // dp[i]代表容量为i的背包最大可以凑成的总和
        vector<int> dp(20000, 0);
        int sum = 0;
        for (auto& num : nums)   
            sum += num;

        if (sum % 2 == 1)   
            return false;
        int target = sum / 2;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
            return true;
        else
            return false;
    }
};
// @lc code=end


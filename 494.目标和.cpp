/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 加号和减号本质将nums中的数字分成两部分：x和y
        // x+y=sum
        // x-y=target
        // 所以有x=(target+sum)/2
        // 那么背包问题本质就是装满容量为x的背包的方法有几种
        int sum = 0;
        for (auto& num : nums)  sum += num;
        if (abs(target) > sum) {
            return 0;
        }
        if ((target + sum) % 2 == 1) {
            return 0;
        }
        int x = (target + sum) / 2;
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = x; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[x];
    }
};
// @lc code=end


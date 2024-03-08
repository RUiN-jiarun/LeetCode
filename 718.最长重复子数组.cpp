/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        // 注意下标的艺术
        // 我们定义dp[i][j]是以nums1[i-1]以及nums2[j-1]为结尾的最长重复子数组长度
        // 这样做的好处是，dp[i][0]和dp[0][j]没有意义，都是0
        // 因此循环从1开始，一直取到出去
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > res) {
                    res = dp[i][j];
                }
            }
        }
        return res;
    }
};
// @lc code=end


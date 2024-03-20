/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int len = INT_MAX;
        int sum = 0;
        for (j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 当sum >= target, i向前挪，缩小窗口大小
            while (sum >= target) {
                int window_size = j - i + 1;
                len = len < window_size ? len : window_size;
                sum -= nums[i++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
// @lc code=end


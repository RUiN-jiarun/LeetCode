/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // 统计滑动窗口内0的数量
        // 转化为：在 cnt0 <= k 的条件下，窗口大小的最小值
        int ans = 0, left = 0, cnt0 = 0;
        for (int right = 0; right < nums.size(); right++) {
            cnt0 += 1 - nums[right]; // 0 变成 1，用来统计 cnt0
            // 当cnt0 > k，可以进行调整，把一个0变成1，left++
            while (cnt0 > k) {
                cnt0 -= 1 - nums[left++];
            }
            // 窗口大小为right-left+1
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end


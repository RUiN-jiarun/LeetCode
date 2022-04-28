/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 双指针问题
        int l = 0;
        int r = height.size() - 1;
        int max_res = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                max_res = max(max_res, height[l] * (r-l));
                l++;
            }
            else {
                max_res = max(max_res, height[r] * (r-l));
                r--;
            }
        }
        return max_res;
    }
};
// @lc code=end


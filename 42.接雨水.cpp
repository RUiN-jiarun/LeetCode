/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftmax = 0, rightmax = 0;
        while (left < right) {
            leftmax = max(height[left], leftmax);
            rightmax = max(height[right], rightmax);
            if (height[left] < height[right]) {
                res += leftmax - height[left];
                left++;
            }
            else {
                res += rightmax - height[right];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end


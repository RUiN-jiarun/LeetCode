/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxstep = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (i <= maxstep) {
        //         maxstep = max(maxstep, i + nums[i]);
        //         if (maxstep >= nums.size() - 1) {
        //             return true;
        //         }
        //     }
        // }
        // return false;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxstep) {
                return false;
            }
            maxstep = max(maxstep, nums[i]+ i);
        }
        return true;
    }
};
// @lc code=end


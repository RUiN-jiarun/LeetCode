/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        // 构建差分
        for (auto& booking : bookings) {
            int first = booking[0] - 1, last = booking[1], seats = booking[2];
            ans[first] += seats;
            // 这里有个坑，如果last==n？无需修改
            if (last != n)
                ans[last] -= seats;
        }
        // 恢复原数组
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};
// @lc code=end


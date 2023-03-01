/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int left = intervals[0][0];
        int right = intervals[0][1];

        for (auto i : intervals) {
            if (i[0] > right) {     // 下一个区间的头大于上一个区间的尾
                res.push_back({left, right});
                left = i[0];
            }
            right = max(right, i[1]);
        }

        res.push_back({left, right});
        return res;

    }
};
// @lc code=end


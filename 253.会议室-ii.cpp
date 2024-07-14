/*
 * @lc app=leetcode.cn id=253 lang=cpp
 *
 * [253] 会议室 II
 */

// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> diff(1000001, 0);       //差分数组  差分
        for (vector<int> v: intervals)
        {
            int start = v[0],   end = v[1];
            diff[start] ++;
            diff[end] --;
        }

        for (int i = 1; i < 1000001; i ++)
            diff[i] += diff[i - 1];
        return *max_element(diff.begin(), diff.end());
    }
};
// @lc code=end


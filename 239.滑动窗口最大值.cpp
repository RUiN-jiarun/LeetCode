/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
private:
    class Monoqueue {
    public:
        deque<int> q;
        void pop(int val) {
            if (!q.empty() && val == q.front()) {
                q.pop_front();
            }
        }
        void push(int val) {
            while (!q.empty() && val > q.back()) {
                q.pop_back();
            }
            q.push_back(val);
        }
        int front() {
            return q.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Monoqueue q;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        res.push_back(q.front());
        for (int i = k; i < nums.size(); i++) {
            q.pop(nums[i - k]); // 移除滑动窗口最前面的元素
            q.push(nums[i]);    // 滑动窗口前加入最后面的元素
            res.push_back(q.front());
        }
        return res;
    }
};
// @lc code=end


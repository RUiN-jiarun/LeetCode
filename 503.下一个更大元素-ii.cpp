/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        // 单调栈：从栈底到栈顶递减
        stack<int> s;
        // 考虑到我们要循环一次遍历，我们可以把nums复制一份
        // [1, 2, 1, 1, 2, 1]
        // [2, -1, 2]
        for (int i = 2 * n - 1; i >= 0; i--) {
            int num = nums[i % n];
            while (!s.empty() && num >= s.top()) {
                s.pop();
            }
            if (i < n && !s.empty()) {
                res[i] = s.top();
            }
            s.push(num);
        }
        return res;
    }
    
};
// @lc code=end


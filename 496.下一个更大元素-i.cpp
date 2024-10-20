/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 显然可以暴力求解，两层遍历，时间复杂度O(mn)
        // 用空间换时间
        // 要求下一个更大的元素，就要用单调栈来解
        unordered_map<int, int> hash;
        stack<int> s;
        // 倒序遍历nums2，维护当前位置右边更大的元素列表，从栈底到栈顶是单调递减的
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while (!s.empty() && num >= s.top()) {
                s.pop();
            }
            hash[num] = s.empty() ? -1 : s.top();
            s.push(num);
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            res.emplace_back(hash[nums1[i]]);
        }
        return res;
    }
};
// @lc code=end


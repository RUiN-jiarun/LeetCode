/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        stack<int> st;
        int res = 0;
        st.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) {
                st.push(i);
            } else if (height[i] == height[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        res += h * w;
                    }
                }
                st.push(i);
            }

        }
        return res;
    }
    int trap_double_ptr(vector<int>& height) {
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


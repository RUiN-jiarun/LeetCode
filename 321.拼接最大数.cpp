/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
public:
    // 准备函数：从给定数组中找到k个最大的数，保持原有顺序
    // 利用单调栈
    vector<int> prepare(const vector<int>& nums, int k) {
        int drop = nums.size() - k; // 需要丢弃的元素数量
        stack<int> st;
        for (int num : nums) {
            while (!st.empty() && st.top() < num && drop > 0) {
                st.pop();
                drop--;
            }
            st.push(num);
        }
        // 返回栈的前k个
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        
        // 如果栈中的元素超过 k 个，只保留前 k 个元素
        if (result.size() > k) {
            result.resize(k);
        }
        return result;
    }

    // 合并函数：将两个数组合并为一个最大数。
    vector<int> merge(const vector<int>& a, const vector<int>& b, int k) {
        vector<int> result;
        auto it1 = a.begin(), it2 = b.begin();
        while (result.size() < k) {
            // 比较两个数组的头部元素，选择较大的一个
            if (lexicographical_compare(it1, a.end(), it2, b.end())) {
                result.push_back(*it2++);
            } else {
                result.push_back(*it1++);
            }
        }
        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> maxResult;
        for (int i = 0; i <= k; ++i) {
            if (i <= nums1.size() && k - i <= nums2.size()) {
                vector<int> candidate = merge(prepare(nums1, i), prepare(nums2, k - i), k);
                if (lexicographical_compare(maxResult.begin(), maxResult.end(), candidate.begin(), candidate.end())) {
                    maxResult = candidate;
                }
            }
        }
        return maxResult;
    }
};
// @lc code=end


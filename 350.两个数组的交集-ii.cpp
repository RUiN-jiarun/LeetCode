/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> mp;
        for (int num : nums1) {
            mp[num]++;
        }
        vector<int> res;
        for (int num : nums2) {
            if (mp.count(num)) {
                res.push_back(num);
                mp[num]--;
                if (mp[num] == 0) {
                    mp.erase(num);
                }
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    // 构建小顶堆
    class comp {
        public:
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // 记录出现次数
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> heap;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            heap.push(*it);
            // 保证堆的大小一直是k
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = heap.top().first;
            heap.pop();
        }
        return res;
    }
};
// @lc code=end


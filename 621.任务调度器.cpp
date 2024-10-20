/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> bucket(26);
        for (char c : tasks) {
            bucket[c - 'A']++;
        }
        // 从大到小排序
        sort(bucket.begin(), bucket.end(), [](int& x,int&y){return x>y;});
        // bucket[0]是最多任务的数量
        // 记录最多任务数量的个数
        int cnt = 1;
        while (cnt < bucket.size() && bucket[cnt] == bucket[0]) {
            cnt++;
        }
        return max(int(tasks.size()), cnt + (n + 1) * (bucket[0] - 1));
    }
};
// @lc code=end


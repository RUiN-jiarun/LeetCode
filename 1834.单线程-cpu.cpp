/*
 * @lc app=leetcode.cn id=1834 lang=cpp
 *
 * [1834] 单线程 CPU
 */

// @lc code=start
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // 注意该CPU调度策略为最短任务优先，因此对于任务队列，我们需要进行一个排序
        // 1. 按照进入时间排序
        // 2. 根据执行用时和下标维护一个小顶堆
        long long timestamp = 0;    // 当前时间戳
        // 需要两个队列：entry和ready，一个是所有任务，一个是待执行任务
        // 所有任务放到entry里
        // 按照时间放入ready里
        // 每次从ready的top取任务
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> entry, ready;
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            entry.push(make_pair(tasks[i][0], i));
        }
        vector<int> res;
        while (!entry.empty() || !ready.empty()) {
            // 目前没有待执行任务
            if (ready.empty()) {
                // 所有任务放入ready
                timestamp = entry.top().first;
                while (!entry.empty() && timestamp == entry.top().first) {
                    ready.push(make_pair(tasks[entry.top().second][1], entry.top().second));
                    entry.pop();
                }
            }
            // 有待执行任务，执行优先级最高的任务，然后添加新任务
            res.emplace_back(ready.top().second);
            timestamp += ready.top().first;
            ready.pop();
            while(!entry.empty() && entry.top().first <= timestamp){ //加入所有已经到达的任务
                ready.push(make_pair(tasks[entry.top().second][1], entry.top().second));
                entry.pop();
            }
        }
        return res;
    }
};
// @lc code=end


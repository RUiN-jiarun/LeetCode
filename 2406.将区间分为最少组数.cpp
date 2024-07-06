/*
 * @lc app=leetcode.cn id=2406 lang=cpp
 *
 * [2406] 将区间分为最少组数
 */

// @lc code=start
class Solution {
public:
    // 方法一：定左议右
    int minGroups_heapsort(vector<vector<int>>& intervals) {
        // 将所有区间按left从小到大排序
        sort(intervals.begin(), intervals.end(), 
            [](auto& a, auto& b) {return a[0] < b[0];});
        // 利用小顶堆，堆顶维护每个组的right
        priority_queue<int, vector<int>, greater<>> heap;
        // 如果当前left大于堆顶，则不重叠，可以更新堆顶：把当前的堆顶pop出来，然后把我的right加进去
        // 如果当前left小于堆顶，发生重叠，必须要创建一个新的组，直接把我的right加进去
        for (auto& interval : intervals) {
            if (!heap.empty() && heap.top() < interval[0]) {
                heap.pop();
            }
            heap.push(interval[1]);
        }
        return heap.size();
    }
    // 方法二：差分数组
    int minGroups(vector<vector<int>>& intervals) {
        // 为了方便从大到小计算，可以利用有序map的红黑树结构来排序
        map<int, int> d;
        for (auto& interval : intervals) {
            d[interval[0]]++;
            d[interval[1] + 1]--;
        }
        int res = 0, sum = 0;
        // 遍历有序的map
        for (auto& item : d) {
            sum += item.second;
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end


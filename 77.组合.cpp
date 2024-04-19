/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    // 解决组合问题，就用回溯法！
    // 1. 确认递归函数的返回值和参数
    vector<vector<int>> result;     // 存放符合条件的结果的集合
    vector<int> path;               // 存放符合条件的结果
    void backtracking(int n, int k, int startIndex) {
        // 2. 确认递归终点：到达叶子节点，此时path的大小为k
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        // 3. 确定单层搜索过程
        // for循环：横向遍历可能的取值
        // 递归：纵向遍历可能的组合
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);  // 处理节点
            backtracking(n, k, i + 1);
            path.pop_back();    // 回溯，撤销节点
        }
    }
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;

    }
};
// @lc code=end


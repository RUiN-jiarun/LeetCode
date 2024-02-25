/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> edges;  // 邻接表存储
    vector<int> visited;
    bool valid = true;
    void DFS(int u) {
        visited[u] = 1;         // u搜索中
        for (int v : edges[u]) {
            // v未被访问
            if (visited[v] == 0) {
                DFS(v);
                if (!valid) {
                    return;
                }
            }
            // v也在搜索中，那么说明有个环
            else if(visited[v] == 1) {
                valid = false;
                return;
            }
        }
        // 顺利结束对u的查找，u记为正常
        visited[u] = -1;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& edge : prerequisites) {
            edges[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                DFS(i);
            }
        }
        return valid;
    }
};
// @lc code=end


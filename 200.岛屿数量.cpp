/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
private:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        // 终止条件：已经遍历过或遇到海水
        if (visited[x][y] || grid[x][y] == '0')
            return;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            // 前进到下一个相邻节点
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) 
                continue;  // 越界了，直接跳过
            DFS(grid, visited, nextx, nexty);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false)); 

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') { 
                    result++; // 遇到没访问过的陆地，+1
                    DFS(grid, visited, i, j); // 将与其链接的陆地都标记上 true
                }
            }
        }
        return result;
    }
};
// @lc code=end


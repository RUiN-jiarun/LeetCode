/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    bool dfs(vector<vector<char>>& board, 
            vector<bool>& visited,
            string& word,
            int row,
            int col,
            int index) {
        if (index >= word.length())  
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;
        }
        visited[row * board[0].size() + col] = true;
        if (dfs(board, visited, word, row - 1, col, index + 1) ||
            dfs(board, visited, word, row + 1, col, index + 1) ||
            dfs(board, visited, word, row, col - 1, index + 1) ||
            dfs(board, visited, word, row, col + 1, index + 1)) {
            
            return true; // 若其中任意一条路径能够匹配成功，则返回true
        }
        visited[row * board[0].size() + col] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0 || board[0].empty()) return false;
        int n = board[0].size();
        vector<bool> visited(m * n, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end


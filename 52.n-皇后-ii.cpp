/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    void backtracking(int n, int row, vector<string>& board) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                backtracking(n, row + 1, board);    // 判断下一层，也就是下一行
                board[row][col] = '.';      // 回溯，撤销
            }
        }
    }
    bool isValid(int row, int col, vector<string>& board, int n) {
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<string> board(n, string(n, '.'));
    //     backtracking(n, 0, board);
    //     return res;
    // }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtracking(n, 0, board);
        return res.size();
    }
};
// @lc code=end


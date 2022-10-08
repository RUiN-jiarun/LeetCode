/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};
        int col[9][10] = {0};
        int block[9][10] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (row[i][num])    return false;
                if (col[j][num])    return false;
                if (block[j / 3 + (i / 3) * 3][num])
                    return false;
                
                row[i][num] = 1;
                col[j][num] = 1;
                block[j / 3 + (i / 3) * 3][num] = 1;
            }
        }
        return true;
    }
};
// @lc code=end


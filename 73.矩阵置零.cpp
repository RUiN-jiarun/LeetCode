/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 利用两个标记变量来记录第一行和第一列是否原本包含0
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                flag_row0 = true;
            }
        }
        // 利用其他行列更新第一行第一列
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        // 利用第一行第一列更新其他行列
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 利用标记变量更新第一行第一列
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }

    void setZeroes_sets(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 用set保留零元素所在的行列号
        unordered_set<int> row_zero, col_zero;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row_zero.insert(i);
                    col_zero.insert(j);
                }
            }
        }
        // 置零
        for (int row : row_zero) {
            for (int j = 0; j < n; j++) {
                matrix[row][j] = 0;
            }
        }
        for (int col : col_zero) {
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
// @lc code=end


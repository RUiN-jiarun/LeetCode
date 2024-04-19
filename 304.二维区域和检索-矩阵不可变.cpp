/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> pre;

    NumMatrix(vector<vector<int>>& matrix) {
        int x = matrix.size(), y = 0;
        if (x > 0) {
            y = matrix[0].size();
        }

        pre.resize(x + 1, vector<int>(y + 1));

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2+1][col2+1] - pre[row2+1][col1] - pre[row1][col2+1] + pre[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end


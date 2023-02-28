/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 思路：用交换代替旋转
        // 先做一次转置，再来一次左右反转
        // 1 2 3    1 4 7    7 4 1
        // 4 5 6 -> 2 5 8 -> 8 5 2
        // 7 8 9    3 6 9    9 6 3
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
// @lc code=end


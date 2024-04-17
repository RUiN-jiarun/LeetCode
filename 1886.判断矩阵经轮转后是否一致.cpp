/*
 * @lc app=leetcode.cn id=1886 lang=cpp
 *
 * [1886] 判断矩阵经轮转后是否一致
 */

// @lc code=start
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int temp;
        bool flag;
        for (int k = 0; k < 4; ++k) {
            // 旋转操作
            // 这种方法直接在原数组上操作了
            // for (int i = 0; i < n / 2; ++i) {
            //     for (int j = 0; j < (n + 1) / 2; ++j) {
            //         temp = mat[i][j];
            //         mat[i][j] = mat[n-1-j][i];
            //         mat[n-1-j][i] = mat[n-1-i][n-1-j];
            //         mat[n-1-i][n-1-j] = mat[j][n-1-i];
            //         mat[j][n-1-i] = temp;
            //     }
            // }
            // 或者利用辅助数组
            vector<vector<int>> tmp = mat;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = tmp[n - j - 1][i];
                }
            }
            
            if (mat == target) {
                return true;
            }
        }
        return false;  

    }
};
// @lc code=end


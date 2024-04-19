/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int startx = 0, starty = 0; // 循环起始位置
        int loop = n / 2;           // 循环次数
        int mid = n / 2;            // 矩阵正中间
        int cnt = 1;                // 用来填数
        int offset = 1;             // 注意控制每一条边遍历的长度。主要是拐角！
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;
            for (j = starty; j < starty + n - offset; j++) {
                res[startx][j] = cnt++;
            }
            for (i = startx; i < startx + n - offset; i++) {
                res[i][j] = cnt++;
            }
            for (; j > starty; j--) {
                res[i][j] = cnt++;
            }
            for (; i > startx; i--) {
                res[i][j] = cnt++;
            }
            // 起始位置变到内圈
            startx++;
            starty++;
            // offset改变，控制遍历长度
            offset += 2;
        }
        if (n % 2 == 1) {
            res[mid][mid] = cnt;
        }
        return res;
    }
};
// @lc code=end


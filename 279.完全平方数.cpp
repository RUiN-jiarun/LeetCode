/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j <= sqrt(i); j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};
// @lc code=end


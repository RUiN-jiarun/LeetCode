/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        int l = 0, t = 0, r = m - 1, b = n - 1;
        while (true) {

            // 从左到右，行不变为t，列在变从l到r
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[t][i]);
                cout << matrix[t][i];
            }
                
            // 最上行完了，t++
            if (++t > b) 
                break;
            
            // 从上到下，列不变为r，行在变从t到b
            for (int i = t; i <= b; i++) {
                res.push_back(matrix[i][r]);
                cout << matrix[i][r];
            }

            // 最右列完了，r--
            if (--r < l) 
                break;

            // 从右到左，行不变为b，列在变从r到l
            for (int i = r; i >= l; i--) 
                res.push_back(matrix[b][i]);
            // 最下行完了，b--
            if (--b < t) 
                break;

            // 从下到上，列不变为l，行在变从b到t
            for (int i = b; i >= t; i--) 
                res.push_back(matrix[i][l]);
            // 最左列完了，l++
            if (++l > r) 
                break;
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int k, int n) {
        // int eggNum = k, floorNum = n;
        // if(eggNum < 1 || floorNum < 1)
        //     return 0;
        // //上一层备忘录，存储鸡蛋数量-1的相应情况
        // vector<int> preCache(floorNum + 1, 0);
        // //当前备忘录，存储当前鸡蛋数量的相应情况
        // vector<int> currentCache(floorNum + 1, 0);
        // //把备忘录每个元素初始化成最大的尝试次数
        // for(int i = 1; i <= floorNum; i ++){
        //     currentCache[i] = i;
        // }
        // for(int n = 2; n <= eggNum; n ++){
        //     preCache = currentCache;
        //     for(int i = 1; i <= floorNum; i ++){
        //         currentCache[i] = i;
        //     }
        //     for (int m = 1; m <= floorNum; m ++){
        //         for(int k = 1; k < m; k ++){
        //             //扔鸡蛋的楼层从1到m枚举一遍，如果当前算出的尝试次数小于上一次的尝试次数
        //             currentCache[m] = min(currentCache[m], max(preCache[k - 1], currentCache[m - k]) + 1);
        //         }
        //     }
        // }
        // return currentCache[floorNum];
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
		int m = 0;
		while (dp[m][k] < n) {
			++m;
			for (int j = 1; j <= k; ++j) {
				dp[m][j] = dp[m - 1][j - 1] + dp[m - 1][j] + 1;
			}
		}
		return m;
    }
};
// @lc code=end


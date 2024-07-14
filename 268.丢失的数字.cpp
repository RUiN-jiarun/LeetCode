/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 法1：排序，O(nlogn),O(logn)
        // 法2：哈希，O(n),O(n)
        // 法3：求和
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int arrSum = 0;
        for (int i = 0; i < n; i++) {
            arrSum += nums[i];
        }
        return total - arrSum;
        // 法4：位运算
        // int res = 0;
        // for (int i = 0; i < n; i++) {
        //     res ^= nums[i];
        // }
        // for (int i = 0; i <= n; i++) {
        //     res ^= i;
        // }
        // return res;
        // 法5：原地哈希，将该出现的数放到该出现的地方，需要用到swap
    }
};
// @lc code=end


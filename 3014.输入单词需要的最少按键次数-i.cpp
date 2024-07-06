/*
 * @lc app=leetcode.cn id=3014 lang=cpp
 *
 * [3014] 输入单词需要的最少按键次数 I
 */

// @lc code=start
class Solution {
public:
    int minimumPushes(string word) {
        // 尽量均匀地分配到8个摁键上
        // 然后再分配，对应的按键次数+1
        int n = word.length();
        int k = n / 8;
        // 均匀分配后的按键总次数x
        // x = 8 * (1 + 2 + ... + k)
        int x = 8 * (1 + k) * k / 2;
        // 剩余的字母要多按k+1次
        int y = (k + 1) * (n % 8);
        return x + y;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 *
 * [1702] 修改后的最大二进制字符串
 */

// @lc code=start
class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            // 从最左边开始遍历，如果是1就不变，如果是0就看能否组成00->10
            // 然后找到接下来的0，把所有的0尽量往后面放
            if (binary[i] == '0') {
                while (j <= i || (j < n && binary[j] == '1')) {
                    j++;
                }
                if (j < n) {
                    binary[j] = '1';
                    binary[i] = '1';
                    binary[i + 1] = '0';
                }
            }
        }
        return binary;
    }
};
// @lc code=end


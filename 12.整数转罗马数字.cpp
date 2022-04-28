/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        pair<int, string> dict[13];
        dict[0] = make_pair(1000, "M");
        dict[1] = make_pair(900, "CM");
        dict[2] = make_pair(500, "D");
        dict[3] = make_pair(400, "CD");
        dict[4] = make_pair(100, "C");
        dict[5] = make_pair(90, "XC");
        dict[6] = make_pair(50, "L");
        dict[7] = make_pair(40, "XL");
        dict[8] = make_pair(10, "X");
        dict[9] = make_pair(9, "IX");
        dict[10] = make_pair(5, "V");
        dict[11] = make_pair(4, "IV");
        dict[12] = make_pair(1, "I");
        string s = "";
        for (auto iter : dict) {
            while (num >= iter.first) {
                num -= iter.first;
                s += iter.second;
            }
            if (num == 0) {
                break;
            }
        }
        return s;
    }
};
// @lc code=end


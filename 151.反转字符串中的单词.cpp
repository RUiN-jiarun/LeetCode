/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    // 但凡用python都秒解了

    void reverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 双指针删除数组元素
    void removeExtraSpaces(string& s) {
        int slow = 0, fast = 0;
        // 去掉前面的空格
        while (s.size() > 0 && fast < s.size() && s[fast] == ' ') {
            fast++;
        }
        // 去掉中间的空格
        for (; fast < s.size(); fast++) {
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ') {
                continue;
            } else {
                s[slow++] = s[fast];
            }
        }
        // 去掉结尾的空格
        if (slow - 1 > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }
    }

    string reverseWords(string s) {
        // 思路：先全部反转，再针对每一个单词反转
        // 难点在于多余空格的删除
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0, end = 0; // 记录反转单词在字符串中的位置
        bool entry = false;     // 标记枚举字符串的过程是否已经进入单词区间
        for (int i = 0; i < s.size(); i++) {
            // 进入单词
            if ((!entry) || s[i] != ' ' && s[i - 1] == ' ') {
                start = i;
                entry = true;
            }
            // 单词后面有空格：分词符
            if (entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1;
                entry = false;
                reverse(s, start, end);
            }
            // 单词后面没有空格：结束
            if (entry && (i == (s.size() - 1)) && s[i] != ' ') {
                end = i;
                entry = false;
                reverse(s, start, end);
            }
        }
        return s;
    }
};
// @lc code=end


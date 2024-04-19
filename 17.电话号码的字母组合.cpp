/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    vector<string> res;
    string s;

    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtracking(digits, index + 1);    // 递归处理下一层数字
            s.pop_back();   // 回溯
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        backtracking(digits, 0);
        return res;
    }
};
// @lc code=end


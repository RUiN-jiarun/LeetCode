/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    // 判断子串是否回文
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j])   return false;
        }
        return true;
    }

    void backtracking(const string& s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {
                continue;
            }
            backtracking(s, i + 1); // 寻找i+1为起点的子串
            path.pop_back();        // 回溯
        }

    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    // 判断是否合法
    bool isValid(const string& s, int start, int end) {
        // 左右区间合法
        if (start > end) {
            return false;
        }
        // 0开头的数字不合法
        if (s[start] == '0' && start != end) { 
                return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            // 遇到非数字字符不合法
            if (s[i] > '9' || s[i] < '0') { 
                return false;
            }
            num = num * 10 + (s[i] - '0');
            // 大于255不合法
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
    // 回溯的时候，用start记录每次切割的开始index，避免重复切割
    // 本题中，需要判断一下切割的数量，也就是小数点的数量
    void backtracking(string& s, int start, int point_num) {
        if (point_num == 3) {
            if (isValid(s, start, s.size()-1)) {
                result.emplace_back(s);
            }
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isValid(s, start, i)) {
                s.insert(s.begin() + i + 1, '.');
                point_num++;
                backtracking(s, i + 2, point_num);
                point_num--;
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        // 这是一个切割问题，用回溯法列举所有可能性，并且进行剪枝
        backtracking(s, 0, 0);
        return result;
    }
};
// @lc code=end


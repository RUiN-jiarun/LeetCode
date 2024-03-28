/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<string> str_stack;
        stack<int> num_stack;
        string res = "";
        int num = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                res += s[i];
            } else if (s[i] == '[') {
                num_stack.push(num);
                num = 0;
                str_stack.push(res);
                res = "";
            } else if (s[i] == ']') {
                int times = num_stack.top();
                num_stack.pop();
                for (int j = 0; j < times; j++) {
                    str_stack.top() += res;
                }
                res = str_stack.top();
                str_stack.pop();
            }
        }
        
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> map(26, 0); // 记录字符串元素出现个数(为了保住最后一个元素不被弹出)
        vector<bool> visited(26, false); // 入栈登记表
        string result; // 栈本体 这里可以直接用string作为栈体
        for (char c : s) map[c - 'a']++; // 准备入栈各元素数量登记
        for (char c : s) {
            // 如果该元素进去过了 就不给进了 别忘了进不去的元素也要把数量减一
            if (visited[c - 'a']) { 
                map[c - 'a']--;
                continue;
            }
            // 如果栈不空 栈顶大于准备压入的元素 栈顶元素不是最后一个幸存者 就要把栈顶弹出来
            while (!result.empty() && result.back() > c && map[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false; // 做好访客登记
                result.pop_back();               
            }
            result.push_back(c); // 新客入栈
            visited[c - 'a'] = true;       
            map[c - 'a']--;
        }
        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums) {
            strs.emplace_back(to_string(num));
        }
        auto cmp = [](string a, string b) {
            return a + b > b + a;
        };
        sort(strs.begin(), strs.end(), cmp);
        stringstream ss;
        for (auto c : strs) {
            ss << c;
        }
        string res = ss.str();
        if (res[0] == '0') {
            return "0";
        } else {
            return res;
        }
    }
};
// @lc code=end


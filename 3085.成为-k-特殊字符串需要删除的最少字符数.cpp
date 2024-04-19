/*
 * @lc app=leetcode.cn id=3085 lang=cpp
 *
 * [3085] 成为 K 特殊字符串需要删除的最少字符数
 */

// @lc code=start
class Solution {
public:
    // 猜想：至少有一种字母不用删除
    // 
    int minimumDeletions(string word, int k) {
        int cnt[26]{};  // 词频统计表
        for (char c: word) {
            cnt[c - 'a']++;
        }
        ranges::sort(cnt);  // 排序

        // 枚举字符i
        int max_save = 0;
        for (int i = 0; i < 26; i++) {
            int sum = 0;
            for (int j = i; j < 26; j++) {
                sum += min(cnt[j], cnt[i] + k); // 出现次数最多的字母，次数不超过cnt[i]+k
            }
            max_save = max(max_save, sum);
        }
        return word.length() - max_save;
    }
};
// @lc code=end


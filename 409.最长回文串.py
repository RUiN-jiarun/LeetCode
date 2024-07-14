#
# @lc app=leetcode.cn id=409 lang=python3
#
# [409] 最长回文串
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # 统计每个字符的个数
        # 偶数都要，奇数只要一个，剩下的奇数都减一之后再要
        temp = []
        ans = 0
        max_ = 0
        tag = True
        for i in s:
            if i not in temp:
                temp.append(i)
                a = s.count(i)   
                if a % 2 == 0:
                    ans += a    
                elif tag:
                    tag = False
                    ans += a
                else:
                    ans += (a - 1)
        return ans

# @lc code=end


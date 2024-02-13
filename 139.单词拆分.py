#
# @lc app=leetcode.cn id=139 lang=python3
#
# [139] 单词拆分
#

# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # dp[i]表示字符串s的前i位能否由wordDict组成
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(1, len(s) + 1):
            for word in wordDict:
                # 条件：word可以匹配以i结尾的字符串，且剩余的字符串可以由wordDict中单词组成
                if i >= len(word) and dp[i-len(word)] and s[i-len(word) : i] == word:
                    dp[i] = True
                    break
        return dp[len(s)]
# @lc code=end


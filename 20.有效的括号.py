#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'}':'{', ']':'[', ')':'('}
        stack = []
        for ch in s:
            if ch in dic:
                if len(stack) == 0 or stack[-1] != dic[ch]:
                    return False
                stack.pop()
            else:
                stack.append(ch)
        if len(stack) == 0:
            return True
        else:
            return False
# @lc code=end


#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#

# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # 动态规划
        if n == 0:
            return []
        ans = [[] for _ in range(n+1)]
        ans[0] = ['']  # n=0
        ans[1] = ['()']  # n=1
        # n=2时，多了一对括号，只可能在之前的括号的内部or外部
        for i in range(2, n+1):
            for j in range(i):
                l1 = ans[j]
                l2 = ans[i-1-j]
                for k1 in l1:
                    for k2 in l2:
                        ans[i].append("({0}){1}".format(k1, k2))
        return ans[n]

# 动态规划的思路
# 已知i<n的所有情况，推导出i=n的情况
# 考虑i=n比起i=n-1的变化
# ans[i]表示i组括号所有有效的组合
# ans[i] = "(ans[p]) + ans[q]"
# 1+p+q=i
# 遍历：p从0到i-1，q从i-1到0

# @lc code=end


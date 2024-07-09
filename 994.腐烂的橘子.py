#
# @lc app=leetcode.cn id=994 lang=python3
#
# [994] 腐烂的橘子
#

# @lc code=start
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # 传播方式类似BFS
        row = len(grid)
        col = len(grid[0])
        d = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        # 列出所有坏的和好的
        bad = {(i, j) for i in range(row) for j in range(col) if grid[i][j] == 2}
        good = {(i, j) for i in range(row) for j in range(col) if grid[i][j] == 1}
        ts = 0
        # 开始传播，每次从good里拿出放到bad，直到good空了
        while good:
            if not bad:
                return -1
            bad = {(i + di, j + dj) for i, j in bad for di, dj in d if (i + di, j + dj) in good}
            good -= bad
            ts += 1
        return ts

        
# @lc code=end


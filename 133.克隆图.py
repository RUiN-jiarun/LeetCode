#
# @lc app=leetcode.cn id=133 lang=python3
#
# [133] 克隆图
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    visited = {}

    def dfs(self, node):
        if not node:
            return
        if node in self.visited:
            return self.visited[node]
        clone = Node(node.val, [])
        self.visited[node] = clone
        for n in node.neighbors:
            clone.neighbors.append(self.dfs(n))
        return clone
    
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        return self.dfs(node)
        
# @lc code=end


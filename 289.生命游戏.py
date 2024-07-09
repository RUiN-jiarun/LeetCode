#
# @lc app=leetcode.cn id=289 lang=python3
#
# [289] 生命游戏
#

# @lc code=start
class Solution:
    
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        import numpy as np
        row,col = len(board),len(board[0])
        # zero padding
        board_tmp = np.array([[0 for _ in range(col+2)] for _ in range(row+2)])
        board_tmp[1:row+1,1:col+1] = np.array(board)
        # kernel
        kernel = np.array([[1,1,1],[1,0,1],[1,1,1]])
        # conv
        for i in range(1,row+1):
            for j in range(1,col+1):
                tmp = np.sum(kernel * board_tmp[i-1:i+2,j-1:j+2])
                if board_tmp[i][j] == 1:
                    if tmp < 2 or tmp > 3:
                        board[i-1][j-1] = 0
                else:
                    if tmp == 3:
                        board[i-1][j-1] = 1
# @lc code=end


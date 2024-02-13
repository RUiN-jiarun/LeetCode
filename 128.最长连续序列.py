#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#

# @lc code=start
class Solution:
    def longestConsecutive_hash(self, nums: List[int]) -> int:
        longest = 0
        num_set = set(nums)
        for num in num_set:
            cur = num
            cur_length = 1
            while cur + 1 in num_set:
                cur += 1
                cur_length += 1
            longest = max(longest, cur_length)
        return longest
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        if len(nums) == 0:
            return 0
        dp = [1] * len(nums)
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                dp[i] = dp[i-1]
            if nums[i] == nums[i - 1] + 1:
                dp[i] = dp[i-1] + 1
        return max(dp)
# @lc code=end


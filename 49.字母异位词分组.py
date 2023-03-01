#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}

        for s in strs:
            key = "".join(sorted(s))
            if key not in mp:
                mp[key] = [s]
            else:
                mp[key].append(s)
        
        return list(mp.values())

# @lc code=end


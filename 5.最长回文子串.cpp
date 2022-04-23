/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0)  return "";
        int maxLen = 1;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right <= s.length()-1 && s[left] == s[right]) {
                int curLen = right - left + 1;
                if (curLen > maxLen) {
                    maxLen = curLen;
                    start = left;                    
            	    end = right;  
                }
                left--;
                right++;
            }
            // Even case
            left = i;            
            right = i + 1;            
            while (left >= 0 && right <= s.length()-1 && s[left] == s[right]) {                
            	int curLen = right - left + 1;
                if (curLen > maxLen) {
                    maxLen = curLen;
                    start = left;                    
            	    end = right;  
                }
                left--;
                right++;           
           }        

        }
        return s.substr(start, maxLen);
    }
};
// @lc code=end


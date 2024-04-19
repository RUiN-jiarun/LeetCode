/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum_1(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        if (nums.size() < 4)   return ans;
        int length = nums.size();
        // 双循环枚举前两个数
        // i指针：第一个数，从0到length-3
        // j指针：第二个数，从i+1到length-2
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                // 重复的数，跳过
                continue;
            }
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                // 超过了target，直接断开
                break;
            }
            if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                // i指的数加上最大的都不够target，跳过找下一个次大的i
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    // 重复的数，跳过
                    continue;
                }
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    // j指的数后面最小的两个加起来也已经超过target，断开
                    break;
                }
                if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    // i+j以及最大的两个数都不够target，跳过找下一个次大的j
                    continue;
                }
                // 双指针问题
                // 参考三数之和
                int left = j + 1, right = length - 1;
                while (left < right) {
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 去重
            if (k > 0 && nums[k] == nums[k-1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 去重
                if (i - k - 1 > 0 && nums[i] == nums[i-1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    if (nums[k] + nums[i] > target - (nums[left] + nums[right])) {
                        right--;
                    }
                    else if (nums[k] + nums[i] < target - (nums[left] + nums[right])) {
                        left++;
                    }
                    else {
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 去重
                        while (right > left && nums[right] == nums[right-1]) {
                            right--;
                        }
                        while (right > left && nums[left] == nums[left+1]) {
                            left++;
                        }
                        // 找到答案，双指针同时收缩？
                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end


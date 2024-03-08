/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
private:
    int quickSort(vector<int>& nums, int k) {
        int pivot = nums[0];
        vector<int> lt, gt, eq;
        for (int num : nums) {
            if (num > pivot)    gt.push_back(num);
            else if (num == pivot)  eq.push_back(num);
            else                lt.push_back(num);
        }
        // 如果第k大元素在大于的里面
        if (k <= gt.size())
            return quickSort(gt, k);
        // 如果第k大元素在小于的里面
        else if (k > nums.size() - lt.size())
            return quickSort(lt, k - (nums.size() - lt.size()));
        else    
            return pivot;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, k);
    }
};
// @lc code=end


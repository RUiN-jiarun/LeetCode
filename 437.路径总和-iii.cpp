/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<long long, int> pre;

    int DFS(TreeNode* root, long long cur, int targetSum) {
        if (!root)  return 0;
        int ret = 0;
        cur += root->val;
        if (pre.count(cur - targetSum)) {
            ret = pre[cur - targetSum];
        }
        pre[cur]++;
        ret += DFS(root->left, cur, targetSum);
        ret += DFS(root->right, cur, targetSum);
        pre[cur]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        pre[0] = 1;
        return DFS(root, 0, targetSum);
    }
};
// @lc code=end


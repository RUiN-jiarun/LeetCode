/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int res = INT_MIN;
    int DFS(TreeNode* root) {
        if (root == nullptr)    return 0;
        int left_sum = max(0, DFS(root->left));
        int right_sum = max(0, DFS(root->right));
        res = max(res, root->val + left_sum + right_sum);
        return root->val + max(left_sum, right_sum);
    }
    int maxPathSum(TreeNode* root) {
        DFS(root);
        return res;
    }
};
// @lc code=end


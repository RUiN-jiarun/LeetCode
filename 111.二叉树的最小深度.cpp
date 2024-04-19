/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)    return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        // 左子树为空，右子树不为空，要往右子树再找
        if (root->left == nullptr && root->right) {
            return 1 + rightDepth;
        }
        // 右子树为空，左子树不为空，要往左子树再找
        if (root->left && root->right == nullptr) {
            return 1 + leftDepth;
        }
        // 左右都空，则为1；左右都不空，找最小的
        return 1 + min(leftDepth, rightDepth);
    }
};
// @lc code=end


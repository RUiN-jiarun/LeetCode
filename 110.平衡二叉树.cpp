/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 自顶向下
    // int getHeight(TreeNode* root) {
    //     if (root == nullptr)    return 0;
    //     else    return max(getHeight(root->left), getHeight(root->right)) + 1;
    // }
    // bool isBalanced(TreeNode* root) {
    //     if (root == nullptr)    return true;
    //     else return abs(getHeight(root->left) - getHeight(root->right)) <= 1 && \
    //                 isBalanced(root->left) && isBalanced(root->right);
    // }
    // 自底向上
    int getHeight(TreeNode* root) {
        if (root == nullptr)    return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }
};
// @lc code=end


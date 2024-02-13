/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        // 中序遍历解决问题，BST中序遍历一定升序！
        // 中序遍历用栈
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }   // 左子树全部入栈
            root = stack.top();
            stack.pop();
            if (root->val <= inorder) {
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool check(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left == nullptr || right == nullptr) {
            return false;
        } else if (left->val == right->val) {
            return check(left->left, right->right) && check(left->right, right->left);
        } else {
            return false;
        }
    }
    bool isSymmetric_recursive(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return check(root->left, root->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)    return true;
        queue<TreeNode*> q;
        // 用队列模拟层序遍历，但是要注意左右子树都要加进去
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if (left == nullptr && right == nullptr)
                continue;
            if (left == nullptr || right == nullptr)
                return false;
            if (left->val != right->val)
                return false;
            // 注意入队列顺序
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
// @lc code=end


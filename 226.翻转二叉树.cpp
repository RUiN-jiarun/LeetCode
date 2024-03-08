/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))    
            return root;
        // BFS，或者说是层序遍历
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            // 从队列里拿出来一个节点
            TreeNode* node = q.front();
            q.pop();
            // 交换该节点左右子树
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};
// @lc code=end


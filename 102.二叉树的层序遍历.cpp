/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> inorder;
        if (root == nullptr)    return inorder;
        // 队列辅助层序遍历
        queue<TreeNode*> q;
        if (root != nullptr)    q.push(root);
        while (!q.empty()) {
            vector<int> current_layer;
            // 易错：由于queue的长度会变化，所以必须用递减的方法递归
            for (int i = q.size(); i > 0; i--) {
                auto node = q.front();
                q.pop();
                current_layer.push_back(node->val);
                if (node->left != nullptr)     q.push(node->left);
                if (node->right != nullptr)    q.push(node->right);
            }
            inorder.push_back(current_layer);
        }
        return inorder;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth_recursive(TreeNode* root) {
        if (root == nullptr)    return 0;
        int left_depth, right_depth;

        left_depth = maxDepth(root->left) + 1;
        right_depth = maxDepth(root->right) + 1;
        
        return max(left_depth, right_depth);
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == nullptr)    return 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            depth++;
            for (int i = q.size(); i > 0; i--) {
                auto node = q.front();
                q.pop();
                if (node->left)     q.push(node->left);
                if (node->right)    q.push(node->right);
            }
        }
        return depth;
    }
};
// @lc code=end


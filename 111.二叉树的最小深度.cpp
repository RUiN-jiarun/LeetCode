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
    int minDepth_iter(TreeNode* root) {
        if (root == nullptr)    return 0;
        int leftDepth = minDepth_iter(root->left);
        int rightDepth = minDepth_iter(root->right);

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

    int minDepth(TreeNode* root) {
        if (root == nullptr)    return 0;
        // 层序遍历
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
            
                q.pop();
                if (node->left)     q.push(node->left);
                if (node->right)    q.push(node->right);
                if (!node->left && !node->right) {
                    // 必须左右子树都为空才到达叶子节点
                    return depth;
                }
            }
        }
        return depth;
    }
};
// @lc code=end


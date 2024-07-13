/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        queue<TreeNode*> q;
        q.push(root);

        bool b = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                // 正向&反向
                v[b ? size - 1 - i : i] = node->val;

                if (node->left)     q.push(node->left);
                if (node->right)    q.push(node->right);
            }
            res.emplace_back(v);
            b = !b;
        }

        return res;
    }
};
// @lc code=end


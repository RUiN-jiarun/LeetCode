/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        // 直接考虑前序遍历
        stack<TreeNode*> stack;
        vector<TreeNode*> v;
        while (root != nullptr || !stack.empty()) {
            // 先左子树遍历到底
            while (root != nullptr) {
                v.push_back(root);
                stack.push(root);
                root = root->left;
            }
            // 退栈，遍历右子树
            root = stack.top();
            stack.pop();
            root = root->right;
        }
        for (int i = 1; i < v.size(); i++) {
            auto prev = v[i - 1];
            auto cur = v[i];
            prev->left = nullptr;
            prev->right = cur;
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        TreeNode* treeNode = new TreeNode(preorder[0]);
        int mid = distance(begin(inorder), find(inorder.begin(), inorder.end(), preorder[0]));
        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> right_pre(preorder.begin() + mid + 1, preorder.end());
        vector<int> left_in(inorder.begin(), inorder.begin() + mid);
        vector<int> right_in(inorder.begin() + mid + 1, inorder.end());

        treeNode->left = buildTree(left_pre, left_in);
        treeNode->right = buildTree(right_pre, right_in);
        return treeNode;
    }
};
// @lc code=end


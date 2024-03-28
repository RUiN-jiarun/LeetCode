/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<int> path;
    void DFS(TreeNode* root, int need) {
        // 到达叶节点且满足条件
        if (!root->left && !root->right && need == 0) {
            res.push_back(path);
            return;
        }
        // 到达叶节点但不满足条件
        if (!root->left && !root->right) {
            return;
        }
        // 左
        if (root->left) {
            path.push_back(root->left->val);
            need -= root->left->val;
            DFS(root->left, need);
            // 回溯
            need += root->left->val;
            path.pop_back();
        }
        // 右
        if (root->right) {
            path.push_back(root->right->val);
            need -= root->right->val;
            DFS(root->right, need);
            // 回溯
            need += root->right->val;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)  return res;
        path.push_back(root->val);
        DFS(root, targetSum - root->val);
        return res;
    }
};
// @lc code=end


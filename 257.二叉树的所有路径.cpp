/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        // 到达叶子节点的情况
        if (!cur->left && !cur->right) {
            string spath;
            for (int i = 0; i < path.size() - 1; i++) {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            result.push_back(spath);
            return;
        }
        // 回溯的情况
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (!root)  return result;
        traversal(root, path, result);
        return result;
    }
};
// @lc code=end


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            // 要一路向左直到底层，先把左遍历完
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            // 栈顶就是要处理的数据
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
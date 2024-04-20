/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // 拿不到head，拿不到node的前序节点，how to play？
        // 4->5->1->9
        // 4->1->1->9
        // 4->1->9
        node->val = node->next->val;
        node->next = node->next->next;

    }
};
// @lc code=end


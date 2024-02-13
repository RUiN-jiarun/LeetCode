/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode* a = head;
        ListNode* b = head->next;
        while (a != b) {
            if (b == nullptr || b->next == nullptr)
                return false;
            a = a->next;
            b = b->next->next;
        }
        return true;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* a = head;
        ListNode* b = head;
        while (true) {
            if (b == nullptr || b->next == nullptr)
                return nullptr;
            a = a->next;
            b = b->next->next;
            if (a == b)
                break;
        }
        b = head;
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return b;
    }
};
// @lc code=end


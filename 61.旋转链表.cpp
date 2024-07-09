/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)  return head;
        ListNode* p = head;
        ListNode* q = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        k %= len;
        p = head;
        while (k--) {
            q = q->next;
        }
        // 开始移动
        while(q->next){
            p = p->next;
            q = q->next;
        }
        q->next = head;
        ListNode* res = p->next;
        p->next = nullptr;
        return res;
    }
};
// @lc code=end


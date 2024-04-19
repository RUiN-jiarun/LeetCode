/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    // 反转子链表
    // 难点在于，需要考虑子链表的头节点和为节点的改变
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* post = p->next;
            p->next = prev;
            prev = p;
            p = post;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;

        while (head) {
            ListNode* tail = pre;
            // 判断剩余部分长度是否大于等于k
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    // 到头了
                    return dummy->next;
                }
            }
            ListNode* post = tail->next;    // 后继节点
            pair<ListNode* , ListNode*> res = myReverse(head, tail);
            head = res.first;
            tail = res.second;
            // 把子链表接到原来链表里
            pre->next = head;
            tail->next = post;
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};
// @lc code=end


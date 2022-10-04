/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 如何在一次扫描中搞定
        // 使用指针ptr1来找到链表的末尾
        // 使用指针ptr2来找到要删除的节点
        ListNode* ptr1 = head;
        ListNode* res = new ListNode(0, head);
        ListNode* ptr2 = res;
        for (int i = 0; i < n; i++) {
            ptr1 = ptr1->next;
        }
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;  // 删除
        return res->next;
    }
};
// @lc code=end


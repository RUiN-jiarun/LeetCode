/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        // 1.首先将链表断成两段
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* secList = slow->next;
        slow->next = nullptr;

        // 2.反转第二段链表
        ListNode* pre = nullptr;
        ListNode* cur = secList;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        // 3.交替插入
        while (pre) {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = pre->next;
            head->next = pre;
            pre->next = tmp1;
            head = tmp1;
            pre = tmp2;
        }
    }
};
// @lc code=end


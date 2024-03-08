/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
            return true;
        // 利用快慢指针找到链表的中间
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 现在slow->next就指向后半部分的头，把后半部分反转一下
        ListNode* pre = nullptr;
        ListNode* right_half = slow->next;
        while (right_half) {
            ListNode* tmp = right_half->next;
            right_half->next = pre;
            pre = right_half;
            right_half = tmp;
        }
        // 判断
        bool res = true;
        while (res && pre) {
            if (head->val != pre->val) {
                res = false;
            }
            pre = pre->next;
            head = head->next;
        }
        return res;
    }
};
// @lc code=end


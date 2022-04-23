/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);      // Create a new List
        ListNode* r = l3;                    // Create pointers to l3
        // r is a dummy head! r->next is the beginning of l3!
        int carry = 0;

        while (l1 || l2) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            sum %= 10;
            r->next = new ListNode(sum);
            r = r->next;
            if (l1)  l1 = l1->next;
            if (l2)  l2 = l2->next;
        }
        if (carry > 0)
            r->next = new ListNode(carry);
        return l3->next;
    }
};
// @lc code=end


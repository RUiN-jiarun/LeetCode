/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return nullptr;
        Node* dummy = head;
        // Node* res = new Node(head->val);
        // Node* ans = res;
        // unordered_map<Node*, Node*> random_map;
        while (dummy) {
            Node* cur = new Node(dummy->val);
            cur->next = dummy->next;
            dummy->next = cur;
            dummy = cur->next;
        }
        dummy = head;
        while (dummy) {
            if (dummy->random == nullptr) {
                dummy->next->random = nullptr;
            } else {
                dummy->next->random = dummy->random->next;
            }
            dummy = dummy->next->next;
        }
        Node* cur = head->next, *pre = head, *res = head->next;
        while (cur->next) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return res;
    }
};
// @lc code=end


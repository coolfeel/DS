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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode *tail = head, *p1 = l1, *p2 = l2;
        int carry = 0, tmp = 0;
        for (; l1 != NULL && l2 != NULL; l1 = l1 -> next, l2 = l2 -> next) {
            tmp = l1 -> val + l2 -> val + carry;
            if (tmp >= 10) {
                carry = tmp / 10;
                if (tail != NULL) {
                    tail -> next = new ListNode(tmp % 10);
                    tail = tail -> next;
                }                               
            } else {
                carry = 0;
                if (tail != NULL) {
                    tail -> next = new ListNode(tmp);
                    tail = tail -> next;
                }                          
            }
            if (l1 -> next == NULL && l2 -> next == NULL) {
                if (!carry)
                    return head -> next;
                else {
                    tail -> next = new ListNode(carry);
                    return head -> next;
                }
            }
        }
        while (l1 != NULL) {
            int mod = l1 -> val + carry;
            if (mod >= 10) {
                carry = mod / 10;
                tail -> next = new ListNode(mod % 10);
                tail = tail -> next;
                l1 = l1 -> next;
            } else {
                carry = 0;
                tail -> next = new ListNode(mod);
                tail = tail -> next;
                l1 = l1 -> next;
            }
        }
        while (l2 != NULL) {
            int mod = l2 -> val + carry;
            if (mod >= 10) {
                carry = mod / 10;
                tail -> next = new ListNode(mod % 10);
                tail = tail -> next;
                l2 = l2 -> next;
            } else {
                carry = 0;
                tail -> next = new ListNode(mod);
                tail = tail -> next;
                l2 = l2 -> next;
            }
        }
        if (carry)
            tail -> next = new ListNode(carry);
        return head -> next;
    }
};

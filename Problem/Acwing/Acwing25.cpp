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
    
    ListNode* iterReverse(ListNode *head) {
        ListNode *tail = NULL, *tmp = NULL;
        while (head != NULL) {
            tmp = head; head = head->next;
            tmp->next = tail;
            tail = tmp;
        }
        return tail;
    }
    
    ListNode* recurReverse(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *tail = recurReverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return tail;
    }
    
    ListNode* reverseList(ListNode* head) {
        // return recurReverse(head);
        return iterReverse(head);
    }
};
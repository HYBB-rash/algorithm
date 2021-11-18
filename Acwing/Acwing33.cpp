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
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        int len = 0;
        for (auto i = pListHead; i; i = i->next) len ++;
        if (len < k) return nullptr;
        auto p = pListHead;
        for (int i = 0; i < len - k; i ++) p = p->next;
        return p;
    }
};
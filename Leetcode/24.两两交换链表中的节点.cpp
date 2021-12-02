/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val( 0 ), next( nullptr ) {}
    ListNode( int x ) : val( x ), next( nullptr ) {}
    ListNode( int x, ListNode *next ) : val( x ), next( next ) {}
};

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
    ListNode *swapPairs( ListNode *head ) {
        ListNode *header = new ListNode( 0, head );
        ListNode *p      = header;

        while ( p->next != nullptr && p->next->next != nullptr ) {
            auto q        = p->next;
            p->next       = q->next;
            q->next       = p->next->next;
            p->next->next = q;
            p             = p->next->next;
        }

        return header->next;
    }
};
// @lc code=end

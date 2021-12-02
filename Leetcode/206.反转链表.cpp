/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList( ListNode *head ) {
        ListNode *last = nullptr;
        ListNode *p    = head;

        while ( p != nullptr ) {
            ListNode *q = p;
            p           = p->next;
            q->next     = last;
            last        = q;
        }

        return last;
    }
};
// @lc code=end

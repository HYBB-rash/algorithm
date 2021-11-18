/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode();
        ListNode *ans = res;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                res->next = new ListNode(l1->val);
                res = res->next, l1 = l1->next;
            } else {
                res->next = new ListNode(l2->val);
                res = res->next, l2 = l2->next;
            }
        }
        if (l1)
            res->next = l1;
        if (l2)
            res->next = l2;
        return ans->next;
    }
};
// @lc code=end

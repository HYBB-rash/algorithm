/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int len = 1;
        auto i = head;
        for (i = i; i->next; i = i->next) len ++;
        k = len - (k % len);
        i->next = head;
        for (int j = 0; j < k; j ++) i = i->next;
        auto ans = i->next;
        i->next = nullptr;
        return ans;
    }
};
// @lc code=end


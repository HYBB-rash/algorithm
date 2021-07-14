/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode *record;
    bool dfs(ListNode *head) {
        if (!head)
            return true;
        bool res = dfs(head->next);
        if (head->val != record->val)
            res = false;
        else res &= true;
        record = record->next;
        return res;
    }
    bool isPalindrome(ListNode *head) {
        record = head;
        return dfs(head);
    }
};
// @lc code=end

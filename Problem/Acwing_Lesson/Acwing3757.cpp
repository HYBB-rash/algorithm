
/*
 *  @File        :   Acwing3757.cpp
 *  @Time        :   2021/07/14 16:30:51
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 考研上机 链表 3
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    void rearrangedList(ListNode *head) {
        int len = 0;
        for (auto p = head; p; p = p->next) len++;

        int r_s = len / 2;
        auto a = head;
        for (int i = 0; i < r_s; i++) a = a->next;
        auto b = a->next, c = b->next;

        a->next = nullptr, b->next = nullptr;
        while (c) {
            auto tmp = c->next;
            c->next = b;
            b = c, c = tmp;
        }

        for (auto p = head, q = b; q;) {
            auto tmp = q;
            q = q->next;

            tmp->next = p->next;
            p->next = tmp;
            p = p->next->next;
        }
    }
};
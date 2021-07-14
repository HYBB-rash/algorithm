
/*
 *  @File        :   Acwing3756.cpp
 *  @Time        :   2021/07/14 16:15:29
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   Acwing 考研上机 链表 2
 */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(NULL) {}
    ListNode(int _val) : val(_val), next(NULL) {}
};

class Solution {
  public:
    ListNode *filterList(ListNode *head) {
        bool record[10000] = {};
        record[abs(head->val)] = true;

        for (auto p = head; p->next;) {
            int x = abs(p->next->val);
            if (record[x]) {
                auto t = p->next;
                p->next = t->next;
                delete t;
            } else {
                record[x] = true;
                p = p->next;
            }
        }

        return head;
    }
};
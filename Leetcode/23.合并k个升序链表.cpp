#include <algorithm>
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
    ListNode() : val( 0 ), next( nullptr ) {}
    ListNode( int x ) : val( x ), next( nullptr ) {}
    ListNode( int x, ListNode *next ) : val( x ), next( next ) {}
};

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    // 实现一个 堆算法
    // 堆中存储 pair<int, ListNode*>
    vector<pair<int, ListNode *>> stk;
    const int INF = 0x3f3f3f3f;
    void down( int u ) {
        int t = u;
        if ( u * 2 < stk.size() && stk[ u * 2 ].first < stk[ t ].first )
            t = u * 2;
        if ( u * 2 + 1 < stk.size() &&
             stk[ u * 2 + 1 ].first < stk[ t ].first )
            t = u * 2 + 1;
        if ( u != t ) {
            swap( stk[ u ], stk[ t ] );
            down( t );
        }
    }
    void get_heap() {
        int n = stk.size() - 1;
        for ( int i = n / 2; i; i-- )
            down( i );
    }
    ListNode *mergeKLists( vector<ListNode *> &lists ) {
        if ( lists.size() == 0 ) return nullptr;
        ListNode *node = new ListNode();
        ListNode *p    = node;

        // 建堆
        stk.push_back( { INF, nullptr } );
        for ( auto &node : lists ) {
            if (node == nullptr) continue;
            stk.push_back( { node->val, node } );
        }
        if (stk.size() == 1) return nullptr;
        get_heap();

        // 堆从顶拿到最小值，然后更新当前的头数值
        // 利用 down() 更新堆的最小值
        while ( stk[ 1 ].first != INF ) {
            p->next         = stk[1].second;
            p               = p->next;
            stk[ 1 ].second = stk[ 1 ].second->next;
            if ( stk[ 1 ].second == nullptr )
                stk[ 1 ].first = INF;
            else
                stk[ 1 ].first = stk[ 1 ].second->val;
            down( 1 );
        }

        return node->next;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    string truncateSentence( string s, int k ) {
        int i = 0;
        for ( i = 0; i < s.size() && k; i++ ) {
            if (s[i] == ' ') k --;
        }
        if ( k == 0 ) return s.substr( 0, i - 1 );
        return s;
    }
};
// @lc code=end

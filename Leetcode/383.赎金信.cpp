/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
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
    bool canConstruct( string ransomNote, string magazine ) {
        int cnt_ran[ 50 ] = { 0 }, cnt_ma[ 50 ] = { 0 };
        for ( auto &c : magazine )
            cnt_ma[ c - 'a' ]++;
        for ( auto &c : ransomNote )
            cnt_ran[ c - 'a' ]++;

        for ( int i = 0; i < 26; i++ ) {
            if ( cnt_ran[ i ] == 0 ) continue;
            if ( cnt_ran[ i ] > cnt_ma[ i ] ) return false;
        }
        return true;
    }
};
// @lc code=end

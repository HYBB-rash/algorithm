/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    bool static cmp( pair<int, int> a, pair<int, int> b ) {
        if ( a.first != b.first ) return a.first > b.first;
        return a.second < b.second;
    }
    vector<string> findRelativeRanks(vector<int> &score) {
        vector<pair<int, int>> rank;
        for ( int i = 0; i < score.size(); i++ ) {
            rank.push_back({score[i], i});
        }
        sort( rank.begin(), rank.end(), cmp );
        vector<string> ans( score.size() );
        for ( int i = 0; i < rank.size(); i++ ) {
            int idx = rank[ i ].second;
            if ( i == 0 ) ans[idx] = "Gold Medal";
            else if ( i == 1 )
                ans[idx] = "Silver Medal";
            else if ( i == 2 )
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string( i + 1 );
        }
        return ans;
    }
};
// @lc code=end

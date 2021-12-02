#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=1846 lang=cpp
 *
 * [1846] 减小和重新排列数组后的最大元素
 */

// @lc code=start
class Solution {
  public:
    int maximumElementAfterDecrementingAndRearranging( vector<int> &arr ) {
        int n = arr.size();
        vector<int> cnt( n + 1 );
        for ( int &v : arr )
            ++cnt[ min( v, n ) ];
        int miss = 0;
        for ( int i = 1; i <= n; i++ )
            if ( cnt[ i ] == 0 )
                ++miss;
            else
                miss -= min( cnt[ i ] - 1, miss );
        return n - miss;
    }
};
// @lc code=end
